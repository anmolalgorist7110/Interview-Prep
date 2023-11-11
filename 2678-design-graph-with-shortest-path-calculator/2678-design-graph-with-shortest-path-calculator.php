<?php

class Graph {
    private $adjList;
    private $n;

    public function __construct($n, $edges) {
        $this->n = $n;
        $this->adjList = array();
        for ($i = 0; $i < $n; $i++) {
            $this->adjList[$i] = array();
        }
        foreach ($edges as $edge) {
            $from = $edge[0];
            $to = $edge[1];
            $cost = $edge[2];
            $this->adjList[$from][] = array($to, $cost);
        }
    }

    public function addEdge($edge) {
        $from = $edge[0];
        $to = $edge[1];
        $cost = $edge[2];
        $this->adjList[$from][] = array($to, $cost);
    }

    public function shortestPath($node1, $node2) {
        $pq = new SplPriorityQueue();
        $dist = array_fill(0, $this->n, PHP_INT_MAX);
        $dist[$node1] = 0;
        $pq->insert(array($node1, 0), 0);
        while (!$pq->isEmpty()) {
            $curr = $pq->extract();
            $node = $curr[0];
            $distance = $curr[1];
            if ($node == $node2) {
                return $distance;
            }
            if ($distance > $dist[$node]) {
                continue;
            }
            foreach ($this->adjList[$node] as $neighbor) {
                $nextNode = $neighbor[0];
                $edgeCost = $neighbor[1];
                $newDist = $distance + $edgeCost;
                if ($newDist < $dist[$nextNode]) {
                    $dist[$nextNode] = $newDist;
                    $pq->insert(array($nextNode, $newDist), -$newDist);
                }
            }
        }
        return -1;
    }
}

?>