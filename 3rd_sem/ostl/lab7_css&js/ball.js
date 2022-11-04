const canvas = document.getElementById("ball");
const ctx = canvas.getContext("2d");
const ball = {
    x: 25,
    y: 25
  };
const velocity = 3;
const startingAngle = 70;
const rad = 20;
let moveX = Math.cos(Math.PI / 180 * startingAngle) * velocity;
let moveY = Math.sin(Math.PI / 180 * startingAngle) * velocity;
const drawMe = () => {
 ctx.clearRect(0, 0, 400, 300);
 if (ball.x > canvas.width - rad || ball.x < rad) moveX = -moveX;
 if (ball.y > canvas.height - rad || ball.y < rad) moveY = -moveY;
 ball.x += moveX;
 ball.y += moveY;
 ctx.beginPath();
 ctx.fillStyle = 'white';
 ctx.arc(ball.x, ball.y, rad, 0, Math.PI * 2);
 ctx.fill();
 ctx.closePath();
}
setInterval(drawMe, 10);