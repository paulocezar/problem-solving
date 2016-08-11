
function msToH(ms) {
    return ((ms / 1000) / 60) / 60
}

function processData(input) {
    input = JSON.parse(input);
    temp = input.initialTemperature
    speed = input.speed
    tgt = new Date(input.endTime).getTime()
    for (var i = 0, len = input.inputs.length; i < len; ++i) {
        var cur = new Date(input.inputs[i].time).getTime()

        var nxt = tgt
        if ((i+1) < len) {
            nxt = new Date(input.inputs[i+1].time).getTime();
        }

        var dur = msToH(nxt - cur)
            if (temp < input.inputs[i].temperature) {
                temp = temp + dur * speed
                if (temp > input.inputs[i].temperature) temp = input.inputs[i].temperature
            } else {
                temp = temp - dur * speed
                if (temp < input.inputs[i].temperature) temp = input.inputs[i].temperature
            }

    }
    console.log(temp)
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
