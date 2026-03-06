#include <iostream>
void sequence() {
    std::cout << "Please enter a positive integer greater than 9\n";
    int n;
    int ans;
    std::cin >> n;
    int cnt = 0;
    std::cout <<n << "->";
    while (n>=10) {
        int c = n;
         ans = 0;
        while (c != 0) {
            int m = c%10;
            c-=m;
            c= c /10;
            ans+=m;
        }
        cnt+=1;
        n = ans;
        if (n>=10) std::cout << ans << "->";
        else std::cout << ans << "\n";
    }
    std::cout <<"Final value: " << ans << "\n";

    std::cout << "Total steps: " << cnt << "\n";
}

void fizzbuzz() {
    int n = 0;
    std::cout << "Please enter a number between 10 and 100:\n";
    std::cin >> n;
    while (!(n>=10 && n<=100)) {
        std::cout << "Invalid input. Please enter a number between 10 and 100:\n";
        std::cin >> n;
    }
    int fizz = 0;
    int buzz = 0;
    int fizzbuzz = 0;
    for ( int i=1; i<n+1; i++) {
        if ( i%3==0 && i%5==0) {
            std::cout << "FizzBuzz\n";
            fizzbuzz+=1;
        }
        else if ( i%3==0) {
            std::cout << "Fizz\n";
            fizz+=1;}
        else if ( i%5==0) {
            std::cout << "Buzz\n";
            buzz+=1;}
        else if ( i%7==0) {
            continue;
        }
        else std::cout << i << "\n";
    }
    std::cout << "--- Summary ---\n";
    std::cout <<"Fizz count : " << fizz << std::endl;
    std::cout <<"Buzz count : " << buzz << std::endl;
    std::cout << "FizzBuzz count : " << fizzbuzz << std::endl;
}
void pattern() {
    int n = 0;
    std::cout <<"Please enter a number between 3 and 9:\n";
    std::cin >> n;
    for (int i=0; i<2*n; ++i) {
       int k = n-abs(n-i);
        for (int j=1; j<k+1; ++j) {
            std::cout << j;
        }
        std::cout <<"\n";
    }

}



// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    sequence();
fizzbuzz();

pattern();

}