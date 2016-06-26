
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

var skip = false;
var tc = 1;

rl.on('line', function(line){
    if (skip === false) {
      skip = line;
    } else {
      console.log("Case #" + (tc++) + ": " + solve(line));
    }
});

function solve(N) {
  if (N == 0) return "INSOMNIA";
  N = parseInt(N);

  var seen = 0;
  var cur = 0;

  do {
    cur += N;
    var ax = cur;
    while (ax != 0) {
      seen |= (1<<(ax%10));
      ax = Math.floor(ax/10);
    }
  } while (seen != 1023);

  return cur;
}
