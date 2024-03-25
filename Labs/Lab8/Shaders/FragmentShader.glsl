#version 330

in vec3 world_position;
in vec3 world_normal;

uniform vec3 light_direction;
uniform vec3 light_position;
uniform vec3 eye_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

uniform vec3 object_color;

uniform int isSpot;
uniform float angle;

layout(location = 0) out vec4 out_color;

void main()
{
	vec3 L = normalize( light_position - world_position );
	vec3 V = normalize( eye_position - world_position );
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
		light = object_color * (ambient_light + aten_fac * (diffuse_light + specular_light));
	} else {
		if (spot_light > cos(cut_off))
		{
			light = object_color * (ambient_light + (light_att_factor + aten_fac) * (diffuse_light + specular_light));
		} else {
			light = ambient_light * object_color;
		}
	}

	out_color = vec4(light, 1);
}