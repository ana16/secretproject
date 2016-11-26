/**
 * 
 */


//file:///C:/Users/Matthew/Google%20Drive/summer%202016/eclipseprogramtest/testestest/WebContent/NewFile.html

function Main(){
}

var mouse = {x:0,y:0};
var xDebug;
var yDebug;
var dragContainer = new createjs.Container();
var global_mouseDownBool = false;
var global_mouseUpBool = false;
// var global_currentCardOverlayForDrag = new card();



$(document).ready(function(){
	//load canvas,stage,yourHand,ticker,
	
	var cnvs = document.getElementById("myCanvas");
	var stage = new createjs.Stage('myCanvas');
	stage.clear();
	stage.update();
	
	var contents;
	
	cnvs.width = window.innerWidth*10 - 30;
	cnvs.height = window.innerHeight*10 - 30;
	
	// placeTilesOnBoard(contents);
	
	var alphaOrNot = 0;
	// var myImage = new Image();
	// myImage.src = 't0.png';
	// myImage.onload = handleImageLoad;
	
	// myImage = new Image();
	// myImage.src = 't3.png';
	// alphaOrNot = 1;
	// myImage.onload = handleImageLoad;
	
	
	
	function readSingleFile(evt) {
	    //Retrieve the first (and only!) File from the FileList object
	    var f = evt.target.files[0]; 

	    if (f) {
	      var r = new FileReader();
	      r.onload = function(e) { 
		      contents = e.target.result;
		      placeTilesOnBoard(contents);
		      // alert(typeof(contents));
		      // alert(contents);
	        // alert( "Got the file.n" 
	        //       +"name: " + f.name + "n"
	        //       +"type: " + f.type + "n"
	        //       +"size: " + f.size + " bytesn"
	        //       + "starts with: " + contents.substr(1, contents.indexOf("n"))
	        // );  
	      }
	      r.readAsText(f);
	    } else { 
	      alert("Failed to load file");
	    }
	}
	
	
	document.getElementById('fileinput').addEventListener('change', readSingleFile, false);
	
	
	function placeTilesOnBoard(contents){
		
		contents = contents.split(';');
		// alert(contents[6399]);
		
		
		// myImage = new Image();
		// myImage.src = 't0.png';
		// // alphaOrNot = 1;
		// myImage.onload = handleImageLoad;
		
		// myImage = new Image();
		// myImage.src = 't2.png';
		// // alphaOrNot = 1;
		// myImage.onload = handleImageLoad;
		
		
		
		alert(contents[1] != 0);
		for(i = 0; i < 80; i++){
			for(j = 0; j < 80; j++){
				
				if(contents[i*80 + j] != 0){
					
					var splitInstance = contents[i*80 + j].split(',');
					
					var myImage = new Image();
					myImage.width = j*50;
					myImage.height = i*50;
					// myImage.alt = 90;
					var srcString = 't' + splitInstance[0] + '.png';
					myImage.src = srcString;
					// alphaOrNot = 1;
					myImage.onload = handleImageLoad;
					alert('shouldload: ' + i + 'and' + j);
					
				}
				
				
			}
			
		}
		
		
		
		
		
		window.scroll(1900,1900);
		stage.update();
		
		
	}

	function handleImageLoad(event) {
            var image = event.target;
            var bitmap = new createjs.Bitmap(image);
            bitmap.scaleX = .1;
            bitmap.scaleY = .1;
            bitmap.x = image.width;
            bitmap.y = image.height;
            bitmap.rotation = image.alt;
            alert("new bitmap at " + bitmap.y + ", " + bitmap.y)
            
            // if(alphaOrNot == 1){
            // 	bitmap.alpha = 0;
            // }
            // else{
            // 	bitmap.alpha = 1;
            // }
            
            stage.addChild(bitmap);
            stage.update();
    }
    
    function readTextFile(file)
	{
	    var rawFile = new XMLHttpRequest();
	    rawFile.open("GET", file, false);
	    // rawFile.onreadystatechange = function ()
	    // {
	    // 	window.alert(rawFile.readyState);
	    //     if(rawFile.readyState === 4)
	    //     {
	    //     	window.alert('completed');
	    //         if(rawFile.status === 200 || rawFile.status == 0)
	    //         {
	    //             var allText = rawFile.responseText;
	    //             alert(allText);
	    //         }
	    //     }
	    // }
	    rawFile.send(null);
	    var allText = rawFile.responseText;
	    return allText;
	}	
});


















