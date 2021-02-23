#version 330

uniform sampler2D texture_1;

in vec3 frag_color;
in vec3 frag_position;
in vec2 frag_texture;
in vec3 frag_normal;

in vec3 world_position;
in vec3 world_normal;

uniform vec3 light_direction;
uniform vec3 light_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

layout(location = 0) out vec4 out_color;

uniform int isSpot;
uniform float angle;

void main()
{

	vec3 L = normalize( light_position - world_position );
	vec3 V = normalize( vec3(1, 1, 1) - world_position );
	vec3 H = normalize( L + V );
	vec3 R = reflect( L, world_normal );

	float ambient_light = material_kd * 0.25;

	float diffuse_light = material_kd * max(dot(L, world_normal), 0);

	float specular_light = material_ks * pow(max(dot(R, V), 0), material_shininess);

	float cut_off = angle;
	float spot_light = dot(-L, light_direction);
	float spot_light_limit = cos(cut_off);

	float linear_att = (spot_light - spot_light_limit) / (1 - spot_light_limit);
	float light_att_factor = pow(linear_att, 2);
	float aten_fac = 1 / pow(length(light_position - world_position), 2);
	vec3 light;
	
	if (isSpot == 0) {
		light = vec3(1, 1, 1) * (ambient_light + aten_fac * (diffuse_light + specular_light));
	} else {
		if (spot_light > cos(cut_off))
		{
			light = vec3(1, 1, 1) * (ambient_light + (light_att_factor + aten_fac) * (diffuse_light + specular_light));
		} else {
			light = vec3(1, 1, 1) * ambient_light;
		}
	}

	out_color = vec4(light, 1) * texture2D(texture_1, frag_texture);
	//out_color = texture2D(texture_1, frag_texture);

}