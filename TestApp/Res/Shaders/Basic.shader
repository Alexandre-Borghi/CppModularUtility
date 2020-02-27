#shader vertex

#version 460 core

in vec4 position;

void main()
{
    gl_Position = position;
}


#shader fragment

#version 460 core

uniform vec4 u_Color;

out vec4 o_Color;

void main()
{
    o_Color = u_Color;
}