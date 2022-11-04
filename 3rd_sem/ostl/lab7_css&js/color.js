function initColorPicker()
{
    var canvasEl = document.getElementById("color");
    var canvasContext = canvasEl.getContext("2d");

    var image = new Image(250, 250);
    image.onload = () => canvasContext.drawImage(image, 0, 0, image.width, image.height); 
    image.src = "colorwheel.jpg";

    canvasEl.onclick = function(mouseEvent) 
    {
      var imgData = canvasContext.getImageData(mouseEvent.offsetX, mouseEvent.offsetY, 1, 1);
      var rgba = imgData.data;

      alert("rgba(" + rgba[0] + ", " + rgba[1] + ", " + rgba[2] + ", " + rgba[3] + ")");
    }
}