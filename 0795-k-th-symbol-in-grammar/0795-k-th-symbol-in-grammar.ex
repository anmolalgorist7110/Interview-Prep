defmodule Solution do
  @spec kth_grammar(n :: integer, k :: integer) :: integer
  def kth_grammar(n, k) do
    helper(k - 1, 0)
  end

  @spec helper(order :: integer, change :: integer) :: integer
  def helper(0, change) do
    rem(change, 2)
  end

  def helper(order, change) do
    if rem(order, 2) == 1 do
      helper(div(order, 2), change + 1)
    else
      helper(div(order, 2), change)
    end
  end
end