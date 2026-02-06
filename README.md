# Fractol – Real-time fractal explorer in C

> Real-time Mandelbrot, Julia and Burning Ship fractal renderer built in C using MiniLibX.

Fractol is an interactive visualization tool that renders mathematical fractals in real time.  
It allows smooth zooming, panning, live parameter tuning and color exploration to better understand complex numbers and fractal geometry.

*![demo](assets/demo.gif) — optional demo GIF*

---

## 🚀 Features

- Real-time zoom (mouse wheel, cursor-centered)
- Smooth panning with arrow keys
- Mandelbrot, Julia and Burning Ship fractals
- Live Julia parameter editing (interactive exploration / animation-like effects)
- 6 color palettes (keys 1–6)
- Event-driven rendering loop
- Instant redraw using off-screen image buffer
- Exit with ESC or window close

---

## Screenshots

*![demo](assets/demo.gif) — optional demo GIF*

## 🛠️ Tech Stack

- C (gcc)
- MiniLibX (42 graphics library)
- X11
- libft (custom standard library)
- Floating-point math & complex numbers
- Event-driven programming

---

## 📥 Installation

### Linux dependencies (required)

``` bash
sudo apt install libx11-dev libxext-dev libbsd-dev
```

### Build

``` bash
git clone --recurse-submodules git@github.com:tomjoy75/Fractol.git
cd fractol
make
``` 

---

## ▶️ Usage

`./fractol mandelbrot` \
`./fractol burning_ship` \
`./fractol julia <real> <imaginary>`

Example:

`./fractol julia -0.8 0.156`

---

## 🎮 Controls

### Navigation

| Key | Action |
|-----|------------------------------|
| Mouse wheel | Zoom in / out (cursor centered) |
| Arrow keys | Move view |
| ESC | Quit |

### Colors

| Key | Action |
|-----|----------------|
| F1 → F6 | Change palette |

### Julia mode

| Key | Action |
|-----|------------------------------|
| W / S | Modify imaginary component |
| A / D | Modify real component |
| Y U I O P | Preset Julia shapes |

---

## 📁 Project Architecture

```
.
├── srcs/
│   ├── rendering.c
│   ├── fractals.c
│   ├── graphics.c
│   ├── colors.c
│   ├── input.c
│   ├── keys.c
│   ├── movement.c
│   ├── zoom.c
│   └── utils.c
│
├── libft/
├── minilibx-linux/
├── fractol.h
├── Makefile
└── README.md
```

---

## 🧠 Lessons Learned

This project was my first real encounter with:
- complex numbers and fractal mathematics
- visualizing mathematical systems through graphics
- building a small real-time rendering pipeline
- drawing into an image buffer before displaying (faster than pixel-by-pixel)
- event-driven programming (keyboard/mouse hooks)
- performance trade-offs between iterations and frame rate
- low-level memory management in C
It also showed how small parameter changes in Julia sets can generate organic, almost animated shapes.

---

*## 💡 Improvements / Roadmap*

*- GIF/animation export tool*  
*- Fullscreen mode*  
*- More palettes / shaders*  
*- Additional fractals*

---

## 📄 License

Educational project — 42 School
