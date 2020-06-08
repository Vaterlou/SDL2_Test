//
//  WidgetContainer.cpp
//  SDL2_Test
//
//  Created by Денис Гончаров on 08.06.2020.
//  Copyright © 2020 Денис Гончаров. All rights reserved.
//

#include "WidgetContainer.hpp"

WidgetContainer::WidgetContainer(SDL_Renderer *render, const std::vector<std::string> &res) : _render(render), destroy(false), quit(false)
{
    SDL_Rect size_button_hidden;
    size_button_hidden.h = 50;
    size_button_hidden.w = 50;
    size_button_hidden.x = 700;
    size_button_hidden.y = 100;
    
    button_hidden = std::make_shared<Widget>(res[3].c_str(), render, size_button_hidden);
    
    SDL_Rect size_button;
    size_button.h = 50;
    size_button.w = 50;
    size_button.x = 700;
    size_button.y = 100;
    
    button = std::make_shared<Widget>(res[2].c_str(), render, size_button);
    
    SDL_Rect size_image;
    size_image.h = 200;
    size_image.w = 200;
    size_image.x = 200;
    size_image.y = 100;
    
    image = std::make_shared<Widget>(res[1].c_str(), render, size_image);
    
    SDL_Rect size_image_hidden;
    size_image_hidden.h = 100;
    size_image_hidden.w = 200;
    size_image_hidden.x = 400;
    size_image_hidden.y = 100;
    
    image_hidden = std::make_shared<Widget>(res[0].c_str(), render, size_image_hidden);
    
    SDL_RenderClear(render);
}

void WidgetContainer::add_event_handling(SDL_Renderer *ren, SDL_Window *win)
{
    while ( true )
    {
        if ( SDL_PollEvent( &ev ) )
        {
            if ( SDL_QUIT == ev.type )
            {
                quit = true;
                SDL_DestroyTexture(image->get_texture());
                SDL_DestroyTexture(image_hidden->get_texture());
                SDL_DestroyTexture(button->get_texture());
                SDL_DestroyTexture(button_hidden->get_texture());
                break;
            }
            else if (SDL_MOUSEMOTION == ev.type)
            {
                if (ev.motion.x >= image->get_rect().x && ev.motion.x <= image->get_rect().x + image->get_rect().w && ev.motion.y >= image->get_rect().y && ev.motion.y <= image->get_rect().y + image->get_rect().h)
                {
                    clear();
                    image->show();
                    button->show();
                    image_hidden->show();
                    render();
                }
                else if (image_hidden->is_visible())
                {
                    clear();
                    image->show();
                    button->show();
                    render();
                }
            }
            else if (SDL_MOUSEBUTTONDOWN == ev.type)
            {
                if (ev.motion.x >= button->get_rect().x && ev.motion.x <= button->get_rect().x + button->get_rect().w && ev.motion.y >= button->get_rect().y && ev.motion.y <= button->get_rect().y + button->get_rect().h)
                {
                    clear();
                    image->show();
                    button_hidden->show();
                    render();
                }
            }
            else if (SDL_MOUSEBUTTONUP == ev.type)
            {
                if (ev.motion.x >= button->get_rect().x && ev.motion.x <= button->get_rect().x + button->get_rect().w && ev.motion.y >= button->get_rect().y && ev.motion.y <= button->get_rect().y + button->get_rect().h)
                {
                    clear();
                    render();
                    destroy = true;
                    break;
                }
            }
            
        }
    }
}

std::shared_ptr<Widget> WidgetContainer::get_image()
{
    return image;
}

std::shared_ptr<Widget> WidgetContainer::get_button()
{
    return button;
}

std::shared_ptr<Widget> WidgetContainer::get_button_hidden()
{
    return button_hidden;
}

std::shared_ptr<Widget> WidgetContainer::get_image_hidden()
{
    return image_hidden;
}

bool WidgetContainer::get_destroy()
{
    return destroy;
}

bool WidgetContainer::get_quit()
{
    return quit;
}

void WidgetContainer::render()
{
    SDL_RenderPresent(_render);
}

void WidgetContainer::clear()
{
    image->set_visible(false);
    image_hidden->set_visible(false);
    button->set_visible(false);
    SDL_RenderClear(_render);
}
