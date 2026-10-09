# cpp-lab

C++ 알고리즘, Modern C++ 기초, 공간 컴퓨팅·시스템 엔지니어링 실험을 위한 개인 학습 저장소입니다.

당장의 목표는 프로그래머스로 국내 대기업 코딩테스트를 준비하면서 C++ 문법과 STL에 익숙해지는 것입니다. 그 위에 Modern C++, 공간 데이터 처리, 메모리와 성능 같은 시스템 주제를 차례로 쌓아 갈 계획입니다.

## 현재 상태

- 프로그래머스 Lv.0 문제 1개(`120802`)를 정리했습니다.
- `language/fundamentals`, `language/stl`은 다룰 범위만 정해 두었고 실습 코드는 아직 없습니다.
- Modern C++, Spatial, Systems, Embedded, Robotics는 계획 단계이며 폴더도 아직 만들지 않았습니다.

## 학습 영역

| 영역 | 위치 | 상태 |
| --- | --- | --- |
| Algorithms: 프로그래머스 코딩테스트 대비 | `algorithms/programmers/` | 진행 중 |
| Language: 기본 문법 | `language/fundamentals/` | 시작 전 |
| Language: STL | `language/stl/` | 시작 전 |
| Language: Modern C++ | `language/modern-cpp/` | 예정 |
| Spatial Computing: 좌표, 기하, 공간 자료구조, 성능 실험 | `labs/spatial/` | 예정 |
| Systems: 메모리, 객체 수명, 성능, 시스템 프로그래밍 | `labs/systems/` | 예정 |
| Embedded / Robotics | `labs/embedded/`, `labs/robotics/` | 장기 관심 영역 |

## 디렉터리 구조

```text
cpp-lab/
├── algorithms/
│   └── programmers/
│       └── lv0/
│           └── 120802/
│               ├── solution.cpp
│               └── test.cpp
├── language/
│   ├── fundamentals/
│   └── stl/
├── docs/
│   └── roadmap.md
├── .clang-format
├── .gitattributes
├── .gitignore
└── README.md
```

`algorithms/company-prep/`, `language/modern-cpp/`, `labs/`, `tools/`, `.github/workflows/`는 실제 콘텐츠나 자동화가 필요해질 때 추가합니다.

## 개발 환경

Windows와 macOS를 오가며 작업하고, 모든 코드는 표준 C++17로 작성합니다. 컴파일러 확장 기능(`<bits/stdc++.h>`, VLA 등)은 쓰지 않습니다.

| 항목 | Windows | macOS |
| --- | --- | --- |
| 컴파일러 | MSYS2 UCRT64 GCC (`g++`) | Apple Clang (`clang++`) |
| 디버거 | GDB | LLDB |
| 표준 | C++17 | C++17 |
| 에디터 | VS Code | VS Code |

- `.vscode/`는 기기마다 컴파일러 경로가 달라서 Git에서 제외합니다. 각 기기에서 `tasks.json`과 `launch.json`을 따로 관리합니다.
- 코드 스타일은 `.clang-format`(LLVM 기반, 4칸 들여쓰기, 100열 제한)을 따릅니다.
- `.gitattributes`가 줄바꿈을 LF로 맞춰서 두 OS 사이의 줄바꿈 차이가 diff에 섞이지 않게 합니다.
- 빌드는 단일 파일 직접 컴파일로 시작하고, 여러 파일로 이루어진 실험이 생기면 그때 CMake를 도입합니다.

## 실행과 테스트

문제 폴더에서 `test.cpp`를 컴파일해 실행합니다. `test.cpp`가 `solution.cpp`를 include하므로 파일 하나만 컴파일하면 됩니다.

Windows (PowerShell, `C:\msys64\ucrt64\bin`이 PATH에 있을 때):

```powershell
cd algorithms/programmers/lv0/120802
g++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.exe
./test.exe
```

macOS:

```bash
cd algorithms/programmers/lv0/120802
clang++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.out
./test.out
```

모든 테스트가 통과하면 `All tests passed.`를 출력하고 종료 코드 0을 반환합니다. 실패하면 실패한 입력을 stderr에 출력하고 1을 반환합니다.

macOS에서도 실행 파일 이름에 `.out`을 붙입니다. `.gitignore`는 `*.exe`와 `*.out`을 제외하는데, 확장자 없는 실행 파일은 걸러지지 않아 `git status`에 나타나기 때문입니다.

VS Code(Windows)에서는 `test.cpp`를 연 상태로 기본 빌드 작업(`Ctrl+Shift+B`)을 실행하거나 `C++17 Debug` 구성으로 디버깅합니다.

## 프로그래머스 문제 관리

문제는 `algorithms/programmers/lv{난이도}/{문제 ID}/`에 둡니다.

| 파일 | 역할 | 필수 |
| --- | --- | --- |
| `solution.cpp` | 프로그래머스에 그대로 제출하는 코드. `main()` 없음 | 예 |
| `test.cpp` | `solution.cpp`를 include하는 로컬 테스트. `main()` 포함 | 예 |
| `README.md` | 접근법, 복잡도, 오답 기록 | 필요할 때만 |

- 문제 ID는 프로그래머스 URL의 실제 ID를 씁니다.
- 난이도는 문제를 등록할 때의 프로그래머스 표기를 따릅니다.
- 문제 지문과 공식 테스트 데이터는 옮겨 적지 않습니다. 테스트에는 직접 만든 입력과 경계값을 씁니다.
- 각 문제 폴더는 다른 폴더에 의존하지 않고 혼자 컴파일됩니다.

## 확장 방향

- 여러 파일로 이루어진 실험이 생기면 타깃별로 독립 빌드되는 CMake 구성을 추가합니다.
- 문제 수가 늘어나면 전체 `test.cpp`를 GCC와 Clang으로 컴파일하는 GitHub Actions 워크플로를 검토합니다.
- 공간 데이터 구조와 시스템 실험은 `labs/` 아래에 주제별로 추가합니다.

단계별 학습 계획은 [docs/roadmap.md](docs/roadmap.md)에 정리했습니다.
