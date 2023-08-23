defmodule Solution do
  @spec reorganize_string(s :: String.t) :: String.t
  def reorganize_string(s) do
    n = String.length(s)
    list = String.to_charlist(s)
    freq = Enum.frequencies(list)

    if (Map.values(freq) |> Enum.max()) * 2 > n + 1 do
      ""
    else
      Enum.sort_by(list, &({Map.get(freq, &1), &1}))
      |> Enum.split(div(n, 2))
      |> zip_lists([])
      |> to_string()
    end
  end

  defp zip_lists({[], []}, ans), do: ans
  defp zip_lists({[], [ch2]}, ans), do: [ch2 | ans]
  defp zip_lists({[ch1 | list1], [ch2 | list2]}, ans) do
    zip_lists({list1, list2}, [ch1, ch2 | ans])
  end
end