//
//  WidgetContainer.hpp
//  SDL2_Test
//
//  Created by Денис Гончаров on 08.06.2020.
//  Copyright © 2020 Денис Гончаров. All rights reserved.
//

#ifndef WidgetContainer_hpp
#define WidgetContainer_hpp

#include <stdio.h>
#include "Widget.hpp"
#include <vector>
#include <string>

class WidgetContainer
{
public:
    WidgetContainer(SDL_Renderer *render, const std::vector<std::string> &res);
    void add_event_handling(SDL_Renderer *ren, SDL_Window *win);
    
    std::shared_ptr<Widget> get_button();
    std::shared_ptr<Widget> get_button_hidden();
    std::shared_ptr<Widget> get_image();
    std::shared_ptr<Widget> get_image_hidden();
    bool get_destroy();
    bool get_quit();
    
    void render();
    void clear();
    
private:
    std::shared_ptr<Widget> button;
    std::shared_ptr<Widget> button_hidden;
    std::shared_ptr<Widget> image;
    std::shared_ptr<Widget> image_hidden;
    
    SDL_Renderer *_render;
    
    SDL_Event ev;
    bool destroy, quit;
};

#endif /* WidgetContainer_hpp */
