
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
      console.log("Case #" + (tc++) + ": " + solve(line.split('')));
    }
});

function solve(N) {

  idx = 1
  while (idx < N.length) {
    if (N[idx] < N[idx-1]) break;
    idx++;
  }

  if (idx != N.length) {
    idx--;
    while (idx >= 0) {
      N[idx]--;
      if (idx > 0 && N[idx] < N[idx-1]) idx--;
      else break;
    }
    idx++;
    while (idx < N.length) N[idx++] = '9';
  }

  nz = 0
  while (N[nz] == '0') nz++

  N = N.slice(nz)

  return N.join('');
}
