<?php
/****************************************************
ShinoEncoder

Encode)
       echo shinoencode('Hello');

Output)
       dicing scratchier effigies combine wrongers centrifugation inflator indecisiveness droopily indestructibility

Decode)
       echo shinodecode("dicing scratchier effigies combine wrongers centrifugation inflator indecisiveness droopily indestructibility");

Output)
      Hello
****************************************************/

function shinoencode($str){
	$dict = array();
	foreach(explode("\r\n",file_get_contents('shinodict.txt')) as $d){
		$dict[strlen($d)][]=$d;
	}
	$output="";
	for($i=0; $i <strlen($str); $i++){
		$c=substr('0'.dechex(ord($str[$i])),-2,1);
		$output=$output.delem().$dict[hexdec($c)+2][rand(0,sizeof($dict[hexdec($c)+2])-1)];
		$c=substr('0'.dechex(ord($str[$i])),-1,1);
		$output=$output.delem().$dict[hexdec($c)+2][rand(0,sizeof($dict[hexdec($c)+2])-1)];
	}
	return $output;
}

function shinodecode($encstr){
	$delimiter=array(chr(9),chr(10),chr(13));
	for($i=33;$i<48;$i++){
		$delimiter[]=chr($i);
	}
	for($i=58;$i<65;$i++){
		$delimiter[]=chr($i);
	}
	for($i=91;$i<97;$i++){
		$delimiter[]=chr($i);
	}
	for($i=123;$i<127;$i++){
		$delimiter[]=chr($i);
	}
	$encoded=trim(str_replace($delimiter,' ',$encstr));
	while(strpos($encoded,'  ')){
		$encoded=str_replace('  ',' ',$encoded);
	}
	$encarray=explode(' ',$encoded);
	if(count($encarray) % 2 != 0){
		array_pop($encarray);
	}
	$output='';
	for($i=0;$i < count($encarray);$i=$i+2){
		$output=$output.chr(
			hexdec(
				dechex(
					(string)(
						strlen(
							$encarray[$i]
						)-2
					)
				).
				dechex(
					(string)(
						strlen(
							$encarray[$i+1]
						)-2
					)
				)
			)
		);
	}
	
	return $output;
	
}
?>
