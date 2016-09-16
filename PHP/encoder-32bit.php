<!DOCTYPE html>
<html>
<head>
<title>Graduate Project Team 1</title>
</head>
<body style="background-color:rgb(223,227,238)">
<form style="position:center" >
<h1><center>Team -1</h1>
<h1><center>Ajay Dinakar Kandavalli & Nikhil Vangeti</h1>
<h1 ><center>Base32 Encoder</h1><BR><BR><BR>
<center>Input <input type="text"  name="x"  id="x"></input><br><br>
<button type="button"  onclick="encode()" style="width:100px"><center>submit</button><BR><BR><BR>
<p>Encoded String:</p>
</form>
<script>
function encode()
 {
var input = document.getElementById("x").value;//input is given by user
len=input.length;
var ascii=input.split("");//spliting the input string to individual characters
for(i=0;i<len;i++)
{
   ascii[i]=ascii[i].charCodeAt(0).toString(2)//converting each character to binary
   
   ascii[i]= new Array(9 - ascii[i].length).join('0')+ascii[i];//adding 0's before each ascii to
 }                                                      //get every ascii binary 8 bits
var bin="";
for(i=0;i<len;i++)//grouping all bytes together
bin+=ascii[i];
binlen=bin.length;
   if((binlen%5)!=0)
   {
 bin=bin+new Array(6-binlen%5).join('0');
   }
  binlen=bin.length;
bin= bin.match(/.{1,5}/g); //spliting the grouped binary to 5bit words
 binlen=bin.length;
 for(i=0;i<binlen;i++)
	 bin[i]=parseInt(bin[i],2).toString(10);//converting the 5bit words to decimal character
	encode="";  
	 for(i=0;i<binlen;i++)//assosiating each decimal character with 32base character
	 {                    //and concatinating the chareters to get the final base32 encoded string
		switch(bin[i])
		{
		case '0':encode+="A";break;
		case '1':encode+="B";break;
		case '2':encode+="C";break;
		case '3':encode+="D";break;
		case '4':encode+="E";break;
		case '5':encode+="F";break;
		case '6':encode+="G";break;
		case '7':encode+="H";break;
		case '8':encode+="I";break;
		case '9':encode+="J";break;
		case '0':encode+="K";break;
		case '11':encode+="L";break;
		case '12':encode+="M";break;
		case '13':encode+="N";break;
		case '14':encode+="O";break;
		case '15':encode+="P";break;
		case '16':encode+="Q";break;
		case '17':encode+="R";break;
		case '18':encode+="S";break;
		case '19':encode+="T";break;
		case '20':encode+="U";break;
		case '21':encode+="V";break;
		case '22':encode+="W";break;
		case '23':encode+="X";break;
		case '24':encode+="Y";break;
		case '25':encode+="Z";break;
		case '26':encode+="1";break;
		case '27':encode+="2";break;
		case '28':encode+="3";break;
		case '29':encode+="4";break;
		case '30':encode+="5";break;
		case '31':encode+="6";break;
		}
	 }
	  encodelen=encode.length;
	 document.getElementById("cal").innerHTML =encode;	 //encode=encoded result
}
</script>
<!-- the php code below used to display the encoded result-->
<?php 
echo '<p id="cal"><b></p>';
?>
</body>
</html>
