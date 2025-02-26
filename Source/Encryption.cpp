#include "Leadwerks.h"
 
namespace Leadwerks
{
    void GetPassword(String& s)
    {
        s.resize(64);
        auto buffer = CreateStaticBuffer(s.Data(), s.size());
		buffer->PokeByte(20, ';');
		buffer->PokeByte(54, 'Q');
		buffer->PokeByte(7, 'd');
		buffer->PokeByte(52, '_');
		buffer->PokeByte(6, '{');
		buffer->PokeByte(42, '+');
		buffer->PokeByte(50, '<');
		buffer->PokeByte(22, 'W');
		buffer->PokeByte(29, '2');
		buffer->PokeByte(14, '$');
		buffer->PokeByte(31, 'm');
		buffer->PokeByte(30, 'U');
		buffer->PokeByte(11, '[');
		buffer->PokeByte(35, 'T');
		buffer->PokeByte(15, 'q');
		buffer->PokeByte(16, 'c');
		buffer->PokeByte(63, '&');
		buffer->PokeByte(26, 'p');
		buffer->PokeByte(25, ']');
		buffer->PokeByte(36, 'B');
		buffer->PokeByte(17, 'J');
		buffer->PokeByte(62, '#');
		buffer->PokeByte(10, 'G');
		buffer->PokeByte(0, 'T');
		buffer->PokeByte(8, 'x');
		buffer->PokeByte(55, '%');
		buffer->PokeByte(4, '&');
		buffer->PokeByte(24, 'A');
		buffer->PokeByte(32, 'S');
		buffer->PokeByte(45, 'X');
		buffer->PokeByte(12, 'X');
		buffer->PokeByte(23, '=');
		buffer->PokeByte(2, 'u');
		buffer->PokeByte(3, '%');
		buffer->PokeByte(37, 'Y');
		buffer->PokeByte(38, 'V');
		buffer->PokeByte(48, 'c');
		buffer->PokeByte(53, 'X');
		buffer->PokeByte(27, '6');
		buffer->PokeByte(40, 'Z');
		buffer->PokeByte(28, 'H');
		buffer->PokeByte(58, '6');
		buffer->PokeByte(51, 'i');
		buffer->PokeByte(56, 'r');
		buffer->PokeByte(59, 'I');
		buffer->PokeByte(18, 'v');
		buffer->PokeByte(47, 'n');
		buffer->PokeByte(39, 't');
		buffer->PokeByte(43, 'B');
		buffer->PokeByte(61, 'V');
		buffer->PokeByte(41, '$');
		buffer->PokeByte(33, '*');
		buffer->PokeByte(49, 't');
		buffer->PokeByte(21, 'L');
		buffer->PokeByte(44, 'x');
		buffer->PokeByte(13, '*');
		buffer->PokeByte(9, '>');
		buffer->PokeByte(1, '4');
		buffer->PokeByte(60, '.');
		buffer->PokeByte(34, 'l');
		buffer->PokeByte(19, 'M');
		buffer->PokeByte(46, 'o');
		buffer->PokeByte(5, 'f');
		buffer->PokeByte(57, 't');

#ifdef _DEBUG
        //Only uncomment this for testing
        //Assert(s == "T4u%&f{dx>G[X*$qcJvM;LW=A]p6H2UmS*lTBYVtZ$+BxXonct<i_XQ%rt6I.V#&");
#endif
    }
}