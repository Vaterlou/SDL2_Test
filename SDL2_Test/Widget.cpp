//
//  Widget.cpp
//  SDL2_Test
//
//  Created by Денис Гончаров on 08.06.2020.
//  Copyright © 2020 Денис Гончаров. All rights reserved.
//

#include "Widget.hpp"

Widget::Widget(const std::string &image_path, SDL_Renderer *render, SDL_Rect &size) :
    _render(render),
    _size(size),
    _visible(false)
{
    _image = SDL_LoadBMP(image_path.c_str());
    _texture = SDL_CreateTextureFromSurface(render, _image);
    SDL_FreeSurface(_image);
}

void Widget::set_id(const std::string &id)
{
    _id = id;
}

void Widget::set_size(int w, int h)
{
    _size.w = w;
    _size.h = h;
}

void Widget::set_positinon(int x, int y)
{
    _size.x = x;
    _size.y = y;
}

bool Widget::is_visible()
{
    return _visible;
}

std::string Widget::get_id()
{
    return _id;
}

SDL_Rect Widget::get_rect()
{
    return _size;
}

SDL_Texture *Widget::get_texture()
{
    return _texture;
}

SDL_Surface *Widget::get_image()
{
    return _image;
}

void Widget::show()
{
    if (!_visible)
    {
        SDL_RenderCopy(_render, _texture, NULL, &_size);
        _visible = true;
        std::cout << _id + " visible" << std::endl;
    }
}

void Widget::set_visible(bool visible)
{
    _visible = visible;
}
