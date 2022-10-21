let box = document.getElementById("box");
let canvas = document.getElementById("canvas2");
let context = canvas.getContext("2d");

let drops,
    maxSpeed = 50,
    spacing = 5,
    xPosition,
    n;

function init() {
  canvas.width = box.clientWidth * 1.3;
  canvas.height = box.clientHeight * 1.3;

  drops = [];
  xPosition = 0;
  n = canvas.width / spacing;

  for (let i = 0; i < n; i++) {
    xPosition += spacing;
    drops.push({
      x: xPosition,
      y: Math.round(Math.random() * canvas.height),
      width: 1.2,
      height: Math.round(Math.random() * canvas.height),
      speed: Math.round(Math.random() * maxSpeed + 10),
    });
  }
}

function rain() {
  context.clearRect(0, 0, canvas.width, canvas.height);
  for (let i = 0; i < n; i++){
    context.fillStyle = "#2e2f1d";
    context.fillRect(drops[i].x, drops[i].y, drops[i].width, drops[i].height);
    drops[i].y += drops[i].speed;

    if (drops[i].y > canvas.height) {
      drops[i].y = 0 - drops[i].height;
    }
  }
  requestAnimationFrame(rain);
}

function main() {
  init();
  rain();
}

window.addEventListener('load', main, false);
window.addEventListener('resize', init, false);