<h1 align="center">☀ Ray Tracing in One Weekend</h1>
<h4 align="center">Implement in Minilibx, C library in 42</h4>

Practice version of [miniRT](https://github.com/cos18/miniRT) that implement [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley using Minilibx, simple C library that manage GUI in macOS.

<br>

## 🛠 Development Environment

- macOS 10.14+
- clang 11.0+
- Minilibx 20200219_beta (Already in project src!)

<br>

## 💻 How to Run

```bash
$ make
$ ./one_week 2
```

### Usage

`./one_week (chapter) (--save)`

- chapter : **Required.** Chapter number that execute (2 ~ 13)
- --save : Optional. Save Image in bmp format. When this flag is off, it's running through Minilibx.

> 😢 --save option is now in develop. When this option is enable, I will add comments in here(README) & commit!

### Progress

- [x] 2. Output an Image
- [x] 3. The vec3 Class
- [ ] 4. Rays, a Simple Camera, and Background
- [ ] 5. Adding a Sphere
- [ ] 6. Surface Normals and Multiple Objects
- [ ] 7. Antialiasing
- [ ] 8. Diffuse Materials
- [ ] 9. Metal
- [ ] 10. Dielectrics
- [ ] 11. Positionable Camera
- [ ] 12. Defocus Blur
- [ ] 13. Where Next?
