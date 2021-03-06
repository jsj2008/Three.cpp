//
//  Box2.h
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Box2__
#define __Three_cpp__Box2__

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Utils.h"

namespace three {
    class Box2 {
        public:
            /* Constructors */
            Box2();
            Box2( glm::vec2 min_vec, glm::vec2 max_vec );
            Box2( const Box2& rhs );
            Box2 clone() const;
            ~Box2();
        
            /* Setters */
            Box2& operator=( const Box2& rhss );
            Box2& set( glm::vec2 min_vec, glm::vec2 max_vec );
            Box2& setFrom( std::vector<glm::vec2>& points );
            Box2& setFrom( glm::vec2 center, glm::vec2 size );
            Box2& makeEmpty();
        
            glm::vec2 center();
            glm::vec2 size();
        
            Box2& expandByPoint( glm::vec2 point );
            Box2& expandByVector( glm::vec2 vector );
            Box2& expandByScalar( float scalar );
        
            glm::vec2 getParameter( glm::vec2 point );
            glm::vec2 clamp( glm::vec2 point );
            float distanceTo( glm::vec2 point );
            Box2& intersects( Box2& box );
            Box2& unions( Box2& box );
            Box2& translate( glm::vec2 offset );
        
            bool contains( glm::vec2 point );
            bool contains( Box2& box );
            bool doesIntersect( Box2& box );
            bool equals( Box2& box );
            bool empty();
        
            glm::vec2 min;
            glm::vec2 max;
            
            friend std::ostream &operator <<( std::ostream& os, const Box2& box ) {
                os << three::Utils::toString( box.min ) << " to " << three::Utils::toString( box.max );
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Box2__) */
