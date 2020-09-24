#define ROTATION_SPEED 0.01 // default 0.01
#define ZOOM_SPEED     0.005 // default 0.005

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
//    fragColor = texture(iChannel0, (floor( (fragCoord*.98 + iResolution.xy*.01 + (fragCoord-iResolution.xy/2.).yx*vec2(-.03,.03)) )+.5) / iResolution.xy);
    fragColor = texture(iChannel0, (fragCoord*(1.0 - 2.0 * ZOOM_SPEED) + iResolution.xy * ZOOM_SPEED + 
    
       (fragCoord-iResolution.xy/2.).yx*vec2(-ROTATION_SPEED, ROTATION_SPEED)) / iResolution.xy);
    
    float t = iTime*.5;
    
    #define BRIGHTNESS 0.3
    
    vec4 col = vec4(sin(t*vec3(13,11,17))*.5 + BRIGHTNESS, 1);
    
    #define RADIUS 60.0
    #define SPEED_X 5.0
    #define SPEED_Y 5.0
    
    vec2 movement_equation = sin(vec2(SPEED_X,SPEED_Y)*t) * RADIUS;
    
    float idx = .0+1.0*smoothstep( 6., 20., length( fragCoord + movement_equation - iResolution.xy/2. ) );
    fragColor = mix( col, fragColor, idx );
}