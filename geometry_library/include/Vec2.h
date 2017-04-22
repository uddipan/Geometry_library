/***************************************************************************
* Vec2.h                                                                   *
*                                                                          *
* Vec2 is a trivial encapsulation of 2D floating-point coordinates.        *
* It has all of the obvious operators defined as inline functions.         *
*                                                                          *
* History:                                                                 *
*   04/01/2003  Initial coding.                                            *
*   Originally designed by Prov Jim Arvo at UC Irvine                      *
***************************************************************************/
#ifndef __VEC2_INCLUDED__
#define __VEC2_INCLUDED__

#include "Geomheader.h"

struct Vec2 {
    inline Vec2()                     { x = 0; y = 0; }
    inline Vec2( double a, double b ) { x = a; y = b; }
    double x;
    double y;
    };

inline double LengthSquared( const Vec2 &A )
    {
    return A.x * A.x + A.y * A.y;
    }

inline double Length( const Vec2 &A )
    {
    return sqrt( LengthSquared( A ) );
    }

inline Vec2 operator+( const Vec2 &A, const Vec2 &B )
    {
    return Vec2( A.x + B.x, A.y + B.y );
    }

inline Vec2 operator-( const Vec2 &A, const Vec2 &B )
    {
    return Vec2( A.x - B.x, A.y - B.y );
    }

inline Vec2 operator-( const Vec2 &A )  // Unary minus.
    {
    return Vec2( -A.x, -A.y );
    }

inline Vec2 operator*( double a, const Vec2 &A )
    {
    return Vec2( a * A.x, a * A.y );
    }

inline Vec2 operator*( const Vec2 &A, double a )
    {
    return Vec2( a * A.x, a * A.y );
    }

inline double operator*( const Vec2 &A, const Vec2 &B )  // Inner product.
    {
    return (A.x * B.x) + (A.y * B.y);
    }

inline Vec2 operator/( const Vec2 &A, double c )
    {
    return Vec2( A.x / c, A.y / c );
    }

inline double operator^( const Vec2 &A, const Vec2 &B ) // Z-component of Cross product.
    {
    return A.x * B.y - A.y * B.x;
    }

inline Vec2& operator+=( Vec2 &A, const Vec2 &B )
    {
    A.x += B.x;
    A.y += B.y;
    return A;
    }

inline Vec2& operator-=( Vec2 &A, const Vec2 &B )
    {
    A.x -= B.x;
    A.y -= B.y;
    return A;
    }

inline Vec2 &operator*=( Vec2 &A, double a )
    {
    A.x *= a;
    A.y *= a;
    return A;
    }

inline Vec2& operator/=( Vec2 &A, double a )
    {
    A.x /= a;
    A.y /= a;
    return A;
    }

inline Vec2 Unit( const Vec2 &A )
    {
    double d = LengthSquared( A );
    return d > 0.0 ? A / sqrt(d) : Vec2(0,0);
    }

inline std::ostream &operator<<( std::ostream &out, const Vec2 &A )
    {
    out << "(" << A.x << ", " << A.y << ") ";
    return out;
    }


#endif


