//
//  main.cpp
//  SDL2_Test
//
//  Created by Денис Гончаров on 07.06.2020.
//  Copyright © 2020 Денис Гончаров. All rights reserved.
//
#include <iostream>
#include <SDL.h>
#include "WidgetContainer.hpp"

std::unique_ptr<WidgetContainer> init_container(SDL_Window *win, SDL_Renderer *ren, const std::vector<std::string> &res)
{
    std::unique_ptr<WidgetContainer> container = std::make_unique<WidgetContainer>(ren, res);
    container->get_image_hidden()->set_id("img2");
    container->get_image()->set_id("img1");
    container->get_button()->set_id("btn1");

    container->get_button()->show();
    container->get_image()->show();
    container->render();
      
    container->add_event_handling(ren, win);
    
    return container;
}

int main( int argc, char *argv[] )
{
    bool change = false;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 1000, 600, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (ren == nullptr){
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    const std::string PATH = "/Users/denisgoncarov/Documents"; //Need change a Path
    
    std::vector<std::string> res1 =
    {
        PATH + "/SDL2_Test/hello.bmp",
        PATH + "/SDL2_Test/tiger.bmp",
        PATH + "/SDL2_Test/button2.bmp",
        PATH + "/SDL2_Test/button1.bmp"
    };
    
    std::vector<std::string> res2 =
    {
        PATH + "/SDL2_Test/helloeveryone.bmp",
        PATH + "/SDL2_Test/korova.bmp",
        PATH + "/SDL2_Test/button2.bmp",
        PATH + "/SDL2_Test/button1.bmp"
    };
    
    auto container = init_container(win, ren, res1);

    while(true)
    {
        if (container->get_quit())
            break;
        if (container->get_destroy() && !change)
        {
            container = init_container(win, ren, res2);
            change = true;
            std::cout << "change to second container";
        }
        else if (container->get_destroy() && change)
        {
            container = init_container(win, ren, res1);
            change = false;
            std::cout << "change to first container";
        }
    }
    
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}
