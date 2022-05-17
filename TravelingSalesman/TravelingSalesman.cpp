#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;



int main()
{
    setlocale(0, "");
    RenderWindow window(VideoMode(900, 900), "");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}