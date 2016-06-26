#!/usr/bin/ruby
# encoding: UTF-8
# coding: UTF-8
# -*- coding: UTF-8 -*-

T = gets.chomp.to_i

(1..T).each { |tc|
  stack = gets.chomp.squeeze
  ans = stack.length
  ans -= 1 if ans.even? == (stack[0] == '-')
  puts "Case ##{tc}: #{ans}"
}
