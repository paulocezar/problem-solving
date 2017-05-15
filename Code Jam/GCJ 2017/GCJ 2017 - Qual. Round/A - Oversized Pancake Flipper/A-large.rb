#!/usr/bin/ruby
# encoding: UTF-8
# coding: UTF-8
# -*- coding: UTF-8 -*-

T = gets.chomp.to_i

(1..T).each { |tc|
  s, k = gets.split
  flips, k = 0, k.to_i

  (s.size-1).downto(k-1) do |idx|
    if s[idx] == '-'
      flips += 1
      (idx-k+1..idx).each do |i|
        s[i] = s[i] == '+' ? '-' : '+'
      end
    end
  end

  did_it = s.chars.none? { |c| c == '-' }
  puts "Case ##{tc}: #{did_it ? flips : "IMPOSSIBLE"}"
}
