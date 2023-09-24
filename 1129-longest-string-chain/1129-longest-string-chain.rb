# @param {String[]} words
# @return {Integer}
def longest_str_chain(words)
    # we can sort by length so as to make sure we check by different characters
   # for every string , we can remove one character and check if the length of the modified string is present or not in the hash 
   # abcd --> bcd 
   # abcd --> acd
   # abcd --> abd
   # abcd --> abc if any of this is present, we can add 1 to the present length. 
   # Initialize present length to 1 
   dp = Hash.new
   words = words.sort_by{|word| word.length }
   n = words.length
   max = 0 
   #[a, b, ba, bca, bda, bdca]

   for i in (0...words.length) do 
      present_length = 1 
      current_word = words[i]
      for j in (0...current_word.length) do 
          str = String.new(current_word)
          str.slice!(j)          
          if dp.has_key?(str) and str.length > 0
            present_length = [present_length, dp[str]+1].max 
          end 
      end 
      dp[current_word] = present_length      
      max = [present_length,max].max
   end 

   max
end 