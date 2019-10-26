open Utils;

for (i in 1 to 100) {
	Js.log("Test " ++ string_of_int(i));
	Js.log(randBackground());
};
