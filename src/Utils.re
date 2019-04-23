let colors = [
	"purple",
	"indigo",
	"blue",
	"green",
	"yellow",
	"orange",
	"red"
];

let max = List.length(colors);
let minDiff = 2;

let randColor = () => {
	let rand = Random.int(max);
	List.nth(colors, rand);
};

let randBackground = () => {
	let diff = Random.int(4) + minDiff;

	let rand1 = Random.int(max);
	let rand2 = switch(rand1 + diff >= max) {
		| true => diff - max
		| false => rand1 + diff
	};

	let direction = switch(Random.int(2)) {
		| 0 => "to right"
		| _ => "to left"
	};
	Js.log(string_of_int(rand1) ++ ", " ++ string_of_int(rand2));

	"linear-gradient(" ++ direction ++ ", " ++ List.nth(colors, rand1) ++ ", " ++
		List.nth(colors, rand2) ++ ")"
};
