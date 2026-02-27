#include <iostream>
#include <string>
#include <cmath>
void myFirstLabScript() {
    std::cout << "What is your name?\n";
    std::string name = "";
    std::cin >> name;
    std::cout <<  "Hello " +name +".\n";
    std::cout << "What is your Student ID?\n";
    std::string id = "";
    std::cin >> id;
    std::cout << "Your ID is " + id + ".\n";
}
void time_logic() {
    std::cout << "Enter time in seconds\n";
    int time;
    std::cin >> time;
int hours = (time)/3600;
int minutes = (time - int(hours)*3600)/60;
int seconds = (time - int(hours)*3600 -int(minutes)*60);
    std::cout << time<<" seconds is "<<hours <<" hours, " << minutes <<" minutes and " << seconds <<" seconds\n";

}
void distance() {
    std::cout << "Enter x1\n";
    float x1;
    std::cin>> x1;
    std::cout << "Enter y1\n";
    float y1;
    std::cin>> y1;
    std::cout << "Enter x2\n";
    float x2;
    std::cin>> x2;
    std::cout << "Enter y2\n";
    float y2;
    std::cin>> y2;
float dist = std::pow((x2-x1),2)+std::pow((y2-y1),2);
dist = std::pow(dist,0.5);
std::cout << "Distance is " << dist << "\n";
}
void pattern() {
    std::cout << "*******\n *****\n  ***\n   *";
}
int main() {
    myFirstLabScript();
    time_logic();
    distance();
    pattern();
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}