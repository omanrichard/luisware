  
   // SFML - Simple and Fast Multimedia Library
   // Copyright (C) 2007-2017 Laurent Gomila (laurent@sfml-dev.org)
   //
   // This software is provided 'as-is', without any express or implied warranty.
   // In no event will the authors be held liable for any damages arising from the use of this software.
   //
   // Permission is granted to anyone to use this software for any purpose,
   // including commercial applications, and to alter it and redistribute it freely,
   // subject to the following restrictions:
   //
   // 1. The origin of this software must not be misrepresented;
   //    you must not claim that you wrote the original software.
   //    If you use this software in a product, an acknowledgment
   //    in the product documentation would be appreciated but is not required.
   //

   // 2. Altered source versions must be plainly marked as such,
   //    and must not be misrepresented as being the original software.
   //
   // 3. This notice may not be removed or altered from any source distribution.
   //
   
    #ifndef SFML_MOUSE_HPP
    #define SFML_MOUSE_HPP
    
   // Headers
    #include <SFML/Window/Export.hpp>
    #include <SFML/System/Vector2.hpp>
    
    
    namespace sf
    {
    class Window;
    
    class SFML_WINDOW_API Mouse
    {
    public:
    
        enum Button
        {
            Left,       
            Right,      
            Middle,     
            XButton1,   
            XButton2,   
    
            ButtonCount 
        };
    
        enum Wheel
        {
            VerticalWheel,  
            HorizontalWheel 
        };
    
        static bool isButtonPressed(Button button);
    
        static Vector2i getPosition();
    
       static Vector2i getPosition(const Window& relativeTo);
   
       static void setPosition(const Vector2i& position);
   
       static void setPosition(const Vector2i& position, const Window& relativeTo);
   };
   
   } // namespace sf
   
   
   #endif // SFML_MOUSE_HP