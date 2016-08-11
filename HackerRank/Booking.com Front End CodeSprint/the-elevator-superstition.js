function isLucky(candidate) {
    return!candidate.includes("4") && !candidate.includes("13")
}
function processData(input) {
    cur = 0
    lucky = 0
    while (cur != input) {
        lucky++
        if (isLucky(lucky.toString())) cur++
    }
    console.log(lucky)
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
