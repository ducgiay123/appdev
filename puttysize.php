<?php 
$npeak = $_POST['Peaks'];
$mdB = $_POST['MaxdB'];
$today = date("Y-m-d H:i:s");
$record = $today . "Number of peaks:" . $npeak . "Max dB value:" . $mdB . "\n" ;

$file = "putty.txt" ;
if(file_exists($file))
	$fp = fopen($file , "a") ;
else 
	$fp = fopen($file , "w") ;
fwrite($fp , $record) ;
fclose($fp) ;
//echo "From Vu duc Trung e1900297\n" ;
?> 
