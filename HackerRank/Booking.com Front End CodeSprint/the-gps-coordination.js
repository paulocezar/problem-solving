function doit(idx, data) {
    switch (data.path[idx]) {
        case 'U': data.start[1]++; break;
        case 'D': data.start[1]--; break;
        case 'L': data.start[0]--; break;
        case 'R': data.start[0]++; break;
    }
}

function same(p1, p2) {
    return p1[0] == p2[0] && p1[1] == p2[1]
}

function print(data, after) {
    console.log(data[0] + "," + data[1] + " " + after)
}

function processData(input) {
    input = JSON.parse(input)
    for (var i = 0, len = input.p1.path.length; i < len; i++) {
        if (same(input.p1.start, input.p2.start)) {
            print(input.p1.start, i)
            return;
        }
        doit(i, input.p1)
        doit(i, input.p2)
    }
    print(input.p1.start, input.p1.path.lenght)
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
