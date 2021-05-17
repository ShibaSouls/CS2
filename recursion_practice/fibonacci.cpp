// implementation of fib value n - 2 + n - 1
// Livia Coduto

#include <iostream>

int fib(int n) {
  if (n == 0 || n == 1)
    return n;

  return (fib(n-1) + fib(n-2));
}

int fibT(int n,  int left,  int right) {
  if (n == 0)
    return left;

  if (n == 1)
    return right;

  return fibT(n-1, right, left+right);
}




int main(){
  
  int n = 0;
  std::cout << "Enter a number: ";
  std::cin >> n;

  std::cout << "Normal recursive:\n";
  for ( int i = 0; i <= n; ++i){
    std::cout << fib(i) << std::endl;
  }

  std::cout << "Tail recursive:\n";
  for ( int i = 0; i <= n; ++i){
    std::cout << fibT(i, 0, 1) << std::endl;
  }
  
  return 0;
}