# 학습 로드맵

우선순위는 Algorithms, Language, Spatial 연계 순서입니다. 각 단계는 앞 단계와 겹쳐서 진행해도 됩니다. 현재는 Phase 1을 시작하는 단계입니다.

## Phase 1: C++ 기본 문법과 STL 적응

- 목표: 코딩테스트에 필요한 문법과 STL을 막힘 없이 쓴다.
- 내용: 입출력, 참조와 포인터, 함수와 클래스 기초, `vector`, `string`, `map`/`set`, `sort`와 람다 비교자
- 위치: `language/fundamentals/`, `language/stl/`, `algorithms/programmers/lv0/`
- 완료 기준: Lv.0 문제를 레퍼런스 없이 풀 수 있다.

## Phase 2: 프로그래머스 Lv.1~2

- 목표: 구현, 문자열, 정렬, 해시, 완전탐색, 그리디, 스택/큐 유형을 안정적으로 푼다.
- 내용: 시간 복잡도 계산, 자주 쓰는 STL 패턴 정리
- 위치: `algorithms/programmers/lv1/`, `algorithms/programmers/lv2/`
- 완료 기준: Lv.2 문제를 제한 시간 안에 절반 이상 푼다.

## Phase 3: 자료구조, 그래프, DP, 시뮬레이션

- 목표: 대기업 코딩테스트의 핵심 유형을 유형별로 익힌다.
- 내용: BFS/DFS, 최단 경로, 유니온 파인드, 우선순위 큐, 이분 탐색, DP, 구현·시뮬레이션
- 위치: `algorithms/programmers/`, 필요하면 `algorithms/company-prep/`
- 완료 기준: 유형별로 대표 문제를 다시 풀 수 있고 오답 원인을 기록해 두었다.

## Phase 4: Lv.3 중심 실전 코딩테스트

- 목표: 실제 시험 시간과 조건에서 문제를 푼다.
- 내용: 시간 제한 모의 시험, 기업별 기출 유형 정리, 오답 복기
- 위치: `algorithms/programmers/lv3/`, `algorithms/company-prep/`

## Phase 5: Modern C++ 심화

- 목표: 알고리즘 풀이를 넘어 C++ 언어 자체를 깊이 이해한다.
- 내용: RAII, 이동 의미론, 스마트 포인터, 템플릿, `constexpr`, 표준 라이브러리 내부 동작, C++20 이후 기능 탐색
- 위치: `language/modern-cpp/`
- 이 단계에서 여러 파일로 된 예제가 생기면 CMake를 도입한다.

## Phase 6: Spatial / Systems 연계 실험

- 목표: 알고리즘과 언어 지식을 공간 데이터와 시스템 주제에 적용한다.
- Spatial: 좌표 변환, 기하 연산, 쿼드트리·k-d 트리·R-트리, 공간 질의 성능 측정
- Systems: 메모리 레이아웃, 객체 수명, 할당자, 캐시 친화적 자료구조, 벤치마크
- 위치: `labs/spatial/`, `labs/systems/`

## Future: Embedded / Robotics

- 관심과 필요가 생기면 시작하는 장기 영역이다.
- 후보 주제: 마이크로컨트롤러용 C++, 리소스 제약 환경, 센서 데이터 처리, 로봇 좌표계와 운동학
- 위치: `labs/embedded/`, `labs/robotics/`
