function parse(str) {
    var sum = 0
    var cur = 0
    for (var i = 0, len = str.length; i < len; ++i) {
        c = str[i]
        if (c >= '0' && c <= '9') {
            cur = 10*cur + (c-'0')
        } else {
            sum += cur
            cur = 0
        }
    }
    sum += cur
    return sum
}
function processData(input) {
    var lines = input.split("\n");
    var msgs = [];

    for (var i = 1, len = lines.length; i < len; ++i) {
        var data = lines[i].split(":");
        msg = data[0].trim() + "."
        var dl = parse(data[1])
        if (dl === 0) console.log(msg);
        else msgs.push([ dl, msg ]);
    }

    msgs.sort(function(a, b) {
        return a[0] - b[0]
    })
    for (var i = 0, len = msgs.length; i < len; ++i) {
        console.log(msgs[i][1])
    }
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
