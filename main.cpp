
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
sf::RenderWindow window(sf::VideoMode(1500, 600), "Bubblesort");
bool sorted = false;
int const  size = 250;
int array[size];
int delay = 10000;
sf::Color cyan(0, 139, 139);
void displaySort(int index)
{
    window.clear();
    for(int k = 0; k < size; k++)
    {
        sf::RectangleShape block(sf::Vector2f(5, array[k]));
        block.setPosition(k*6, 600-array[k]);

        if(k == index)
        {
            block.setFillColor(sf::Color::Green);
        }
        if(sorted)
        {
            block.setFillColor(cyan);
        }
        
        
        
        window.draw(block);
    }
    window.display();




}
void bubbleSort()
{
    usleep(delay * 50);
    int temp;
    int i;
    for(i = 0; i < size; i++)
    {
        
        for(int j = 0; j < size -1; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                
            }
            displaySort(j);

        }

    }
    sorted = true;

    displaySort(i);
}



int main()
{
   
    srand((unsigned) time(NULL));

    for(int i = 0; i < size; i++)
    {
        array[i] = rand()%600;
    }
    

    

   
    

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(!sorted)
        {
            displaySort(0);
            bubbleSort();
        }
        
        
    }

    return 0;
}
