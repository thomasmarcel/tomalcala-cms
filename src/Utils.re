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
		| true => rand1 + diff - max
		| false => rand1 + diff
	};

	let direction = switch(Random.int(2)) {
		| 0 => "to right"
		| _ => "to left"
	};

	"linear-gradient(" ++ direction ++ ", " ++ List.nth(colors, rand1) ++ ", " ++
		List.nth(colors, rand2) ++ ")"
};
