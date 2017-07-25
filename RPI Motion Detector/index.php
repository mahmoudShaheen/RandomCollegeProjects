<!doctype html>

<html>
	<head>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<title>camProject</title>
		<meta name="language" content="en" />
		<meta name="description" content="" />
		<meta name="keywords" content="" />
		<meta http-equiv="refresh" content="1">
		<style type="text/css">
			ul li {list-style: none; margin-bottom: 15px;}
			ul li img {display: block;}
			ul li span {display: block;}
			img {display: block; margin: auto; width: 40%;}
			body {background-color: white;}
			text-align: center;
		</style>
	</head>
	<body>

		<?php

		// open this directory
		$myDirectory = opendir("images");

		// get each entry
		while($entryName = readdir($myDirectory)) {
			$dirArray[] = $entryName;
		}

		// close directory
		closedir($myDirectory);

		//	count elements in array
		$indexCount	= count($dirArray);

		?>

		<ul>

			<?php
			// loop through the array of files and print them all in a list
			for($index=0; $index < $indexCount; $index++) {
				$extension = substr($dirArray[$index], -3);
				if ($extension == 'jpg'){ // list only jpgs
					echo "<div style='text-align:center'><span> $dirArray[$index]  </span></div>";
					echo '<li><img src="images/' . $dirArray[$index] . '" alt="Image" />';
				}
			}
			?>

		</ul>
	</body>
</html>
