### BOJ [2343] 기타 레슨
> https://www.acmicpc.net/problem/2343

블루레이의 크기가 작아질수록 모든 강의를 녹화하기 위해 필요한 블루레이의 개수가 많아집니다. 강토는 이미 블루레이의 개수를 정했으므로, 블루레이 크기가 일정 이상 작아지면 모든 강의를 담아낼 수 없게 됩니다. 반대로 블루레이의 크기가 커지면 한 블루레이에 담을 수 있는 강의가 늘어나므로 M개 이내로 충분히 가능해집니다. 따라서 블루레이 크기에 따라 전체 강의를 녹화할 수 있는지에 대한 Parametric Search로 해결할 수 있습니다.

이 때 블루레이 크기에 따라 모든 강의를 녹화할 수 있는지 판단할 수 있는 결정 조건은 [`CH07-09. [6236] 용돈 관리`](https://www.acmicpc.net/problem/6236)와 유사하게 지정한 블루레이 크기에 대해 최대한 영상들을 효율적으로 배치할 때 필요한 블루레이 개수가 강토가 정한 블루레이 개수 이내인지를 통해 확인할 수 있습니다. 각 블루레이 크기마다 O(N)의 시간복잡도가 필요하므로 총 시간복잡도는 O(N * log(블루레이 최대 크기))가 됩니다.