//
//  Widget.hpp
//  SDL2_Test
//
//  Created by Денис Гончаров on 08.06.2020.
//  Copyright © 2020 Денис Гончаров. All rights reserved.
//

#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL.h>

class Widget
{
public:
    
    Widget( const std::string &image_path, SDL_Renderer *render, SDL_Rect &size );
    void show();
    
    void set_id(const std::string &id);
    void set_visible(bool visible);
    void set_size(int w, int h);
    void set_positinon(int x, int y);
    bool is_visible();
    
    SDL_Texture *get_texture();
    SDL_Surface *get_image();
    
    std::string get_id();
    SDL_Rect get_rect();
    
    
private:
    std::string _id;
    SDL_Surface *_image;
    SDL_Texture *_texture;
    SDL_Renderer *_render;
    SDL_Rect _size;
    bool _visible;
    
    
};

#endif /* Widget_hpp */
