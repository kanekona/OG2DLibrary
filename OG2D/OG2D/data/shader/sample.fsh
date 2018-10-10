//
// フラグメントシェーダー
//

#version 450


uniform vec3 kdcolor;
uniform vec3 kscolor;
uniform float nscolor;
in vec3 e_normal;
in vec3 e_v;
out vec4 out_color;

void main()
{
  vec3 n = normalize(e_normal);
  vec3 light_v = normalize(vec3(1,1,1));
  float deffuse = max(dot(light_v,n),0.0);
  float specular = pow(max(dot(-normalize(e_v),reflect(-light_v,n)),0.0),nscolor);
  float l = 0.5;
  out_color = vec4(kdcolor*deffuse+kscolor*specular,1.0)+vec4(kdcolor,1.0)*vec4(1,1,1,1.0);
}
