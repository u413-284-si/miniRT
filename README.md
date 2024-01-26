# miniRT
You know you have been ray tracing too long when you wonder which RT God used.

[LINK](https://u413-284-si.github.io/miniRT) to documentation

## Intro
A first introduction into the world of 3D computer graphics and CGI (computer generated images) - widely used in the filming and gaming industry.

The project covers the topic of ray tracing - a technique used to create/render digital images artificially. In contrast to other techniques as ray casting, it is more complex requiring a higher computational cost. In exchange for this greater effort the quality of the generated images in terms of visual fidelity is much higher. 

Ray tracing is the method of creating and shooting rays from an observer (called camera) through the pixels of a virtual screen (viewport) into the artificial scene and then calculating the colour of any object (hittable) that is hit by the ray and is closest to the viewport. Each ray must be tested for intersection with all the hittables in the scene. Once the nearest object has been identified, the colour is obtained at the very intersection point. The colour depends on different conditions such as the position of the camera, the position of one or more light sources, material properties of the hittable and of course the colour of the hittable.

Every hittable is described mathematically in order to calculate whether an intersection occured or not. More complex hittables require a superposition of different base calculations such as cylinders or cones.

## Sample renders
<table align=center>
	<thead>
		<tr>
			<th colspan=2>Bonus demonstration</th>
		</tr>
	</thead>
  <tbody>
      <tr>
        <td><image src="renders/bonus.png"></image></td>
      </tr>
  </tbody>
</table>

<table align=center>
	<thead>
		<tr>
			<th colspan=2>White</th>
		</tr>
	</thead>
  <tbody>
      <tr>
        <td><image src="renders/white.png"></image></td>
      </tr>
  </tbody>
</table>

<table align=center>
	<thead>
		<tr>
			<th colspan=2>Spheres</th>
		</tr>
	</thead>
  <tbody>
      <tr>
        <td><image src="renders/spheres.png"></image></td>
      </tr>
  </tbody>
</table>

<table align=center>
	<thead>
		<tr>
			<th colspan=2>Reflections</th>
		</tr>
	</thead>
  <tbody>
      <tr>
        <td><image src="renders/reflection.png"></image></td>
      </tr>
  </tbody>
</table>

<table align=center>
	<thead>
		<tr>
			<th colspan=2>More renders</th>
		</tr>
	</thead>
  <tbody>
      <tr>
	<td><image src="renders/complex.png"></image></td>
        <td><image src="renders/shadows.png"></image></td>
      </tr>
      <tr>
	<td><image src="renders/pokeball.png"></image></td>
        <td><image src="renders/snowman.png"></image></td>
      </tr>
  </tbody>
</table>

## Project overview

Following a short summary of the features covered by the project:

- Basic objects:
  - sphere
  - plane
  - cylinder
- 2nd degree object:
  - cone (bonus part)
- Interactive GUI:
  - translation & rotation of objects
  - translation of light source(s)
  - manipulation of object & light parameters
  - translation & rotation of camera
- Full Phong lighting modell:
  - diffusive lighting
  - ambient lighting
  - specular lighting (bonus part)
- Reflections (bonus part)
- Coloured light sources (bonus part)
- Texture mapping: 
  - Checker texture (bonus part)
- Accumulative, temporal anti-aliasing for smoother scene transitions by reducing jagged edges (bonus part)
- Multi-threaded processing (bonus part)
- Export of rendered images as ppm files
- FPS calculation

## Installation and Usage

```
git clone git@github.com:u413-284-si/minirt.git minirt
cd minirt
make
./minirt scenes/<choose a scene>
```

For bonus program (inside of minirt directory):

```
make bonus
./minirt_supreme scenes/<choose a scene>
```
Scene files have the .rt-extension. Scenes marked with *#bonus* in the beginning can only be processed with the bonus program.

## Contact & contribute

To contact me and for feedback in order to fix bugs/improve the project you may write me a message to Discord u413q#6851. Or simply create a merge request ;)

