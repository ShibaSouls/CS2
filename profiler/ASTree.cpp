/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2021 Kent State University. All rights reserved.
 *  Spring 2021
 *  Modified by:
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(const std::vector<std::string>& profileName) {
    tree->mainHeader(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profileName) {
    tree->funcCount(profileName);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


/////////////////////////////////////////////////////////////////////
// Destructor for AST
//
AST::~AST() {
    //Recursively traverse tree and delete from bottom up
    std::list<AST*>::const_iterator i = child.begin(); 
        while(!child.empty() && i != child.end()) 
            delete *i++;
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.tag;
    text = actual.text;
    
    for(std::list<AST*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i){
        child.push_back(new AST(**i));
    }
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
    //Swap all the top level childern (pointers to AST)
    nodes tempNode;
    tempNode = nodeType;
    nodeType = b.nodeType;
    b.nodeType = tempNode;
    
    
    std::string temp;
    temp = text;
    text = b.text;
    b.text = temp;
    
    temp = tag;
    tag = b.tag;
    b.tag = temp;
    
    temp = closeTag;
    closeTag = b.closeTag;
    b.closeTag = temp;
    
    // swap child
    child.swap(b.child);
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for milestone 3
//

AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//  There are two types of names.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from an AST node.
//
// IMPORTANT for milestone 3
//

std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//

void AST::mainHeader(const std::vector<std::string>& profileName) {
    std::string profileString = "#include \"profile.hpp\"";
    std::list<AST*>::iterator obj = child.begin();
    while (((*obj)->tag != "function") ) {
        obj++; 
    }
    child.insert(obj, new AST(token, profileString));
    std::vector<std::string>::const_iterator i = profileName.begin();
    while(i != profileName.end()) {
        std::string fileCpp = (*i);
        size_t j = 0; 
        while(j != fileCpp.length()){
            if(fileCpp[j] == '_')
                fileCpp[j] = '.';
            ++j;           
        }
        profileString = "\nprofile " + (*i) + "(\"" + fileCpp + "\")" + ";\n"; 
        child.insert(obj, new AST(token, profileString));
        ++i;  
    }    
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {
    std::list<AST*>::iterator obj = child.begin();
    while (((*obj)->tag != "function") ) {
        obj++;
    }
    std::string fileCpp = profileName;
    size_t j = 0; 
    while(j != fileCpp.length()){
        if(fileCpp[j] == '_')
            fileCpp[j] = '.';
        ++j;           
    }
    std::string profileString = "#include \"profile.hpp\"";
    profileString = profileString + "\nextern profile " + profileName + ";\n\n"; 
    child.insert(obj, new AST(token, profileString));
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(const std::vector<std::string>& profileName) {
     std::list<AST*>::iterator it = child.begin();
     while(it != child.end()) {
        if(((*it)->tag == "function") && ((*it)->getName() == "main")) {
            AST *blockptr = (*it)->getChild("block");
            std::list<AST*>::iterator blockIt = blockptr->child.begin();
            while((*blockIt)->tag != "return") {
                ++blockIt;
            }
            --blockIt;
            AST *output = new AST(token);
            std::string outputCode;
            for(std::vector<std::string>::const_iterator i = profileName.begin(); i !=profileName.end(); ++i) {
                outputCode = outputCode + ("std::cout<< " + (*i) + " <<std::endl; \n");
            }
            output->text = outputCode;
            blockptr->child.insert(blockIt,output);
        }
    ++it; 
  } 
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//

void AST::funcCount(const std::string& profileName) {
    std::list<AST*>::iterator it = child.begin();
    while(it!=child.end()) {
        if( ((*it)->tag == "function") || ((*it)->tag == "constructor") ||  ((*it)->tag == "destructor"))  {
            AST *block = (*it)->getChild("block");
            std::string funcName,countCode;
            AST *name = (*it)->getChild("name");
            AST *nameChild = name->child.front();
            funcName = nameChild->text;
            countCode = " " + profileName +".count(__LINE__, \"" + funcName + "\"); \n";
            AST *count = new AST(token);
            count -> text = countCode;
      
            std::list<AST*>::iterator blockIt = block->child.begin();
            while((*blockIt)->text != "{") {
                ++blockIt;
            }
            ++blockIt;
            block->child.insert(blockIt,count);
        }
    ++it;
  }
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//

void AST::lineCount(const std::string& profileName) {
    std::string countCode = (" " + profileName +".count(__LINE__); \n");
    std::list<AST*>::iterator it = child.begin();

    while(it != child.end()) {
        if(! (*it)->child.empty()) {
            (*it)->lineCount(profileName);
        }

        if((*it)->tag == "expr_stmt") {
            AST *count = new AST(token);
            count->text = countCode;
            (*it) -> child.push_back(count);
        }
        ++it;
  }
}  


/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node
        else
            (*i)->print(out);    //Category node
    }
    return out;
}

    

/////////////////////////////////////////////////////////////////////
// Utilities
//


/////////////////////////////////////////////////////////////////////
// This returns true if a syntactic category is encountered that
//  will not be profiled.
//
// This is IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}


/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}