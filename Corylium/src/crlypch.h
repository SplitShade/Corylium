#pragma once

// Standard Library Headers
#include <iostream>     // Input/Output streams
#include <fstream>      // File streams
#include <sstream>      // String streams
#include <string>       // std::string, std::wstring
#include <cmath>        // Math functions (e.g., sin, cos, sqrt)
#include <cassert>      // Debugging and assertions

// Containers
#include <vector>       // Dynamic array
#include <array>        // Fixed-size array
#include <deque>        // Double-ended queue
#include <list>         // Doubly-linked list
#include <set>          // Ordered sets
#include <unordered_set>// Unordered sets (hash sets)
#include <map>          // Ordered maps (associative containers)
#include <unordered_map>// Unordered maps (hash maps)
#include <queue>        // Queue (FIFO)
#include <stack>        // Stack (LIFO)
#include <tuple>        // std::tuple

// Algorithms and Utilities
#include <algorithm>    // Standard algorithms (e.g., sort, find, transform)
#include <functional>   // Function objects, std::function
#include <utility>      // Utility functions (e.g., std::move, std::forward)
#include <iterator>     // Iterators
#include <memory>       // Smart pointers (e.g., std::unique_ptr, std::shared_ptr)
#include <chrono>       // Time utilities (e.g., std::chrono::duration)
#include <random>       // Random number generators
#include <numeric>      // Numeric operations (e.g., accumulate, partial_sum)
#include <type_traits>  // Type traits (e.g., std::is_same, std::enable_if)

// Threading and Synchronization
#include <thread>       // std::thread
#include <mutex>        // Mutexes for thread synchronization
#include <atomic>       // Atomic operations
#include <condition_variable> // Condition variables for synchronization
#include <future>       // Asynchronous function calls (e.g., std::async, std::future)

// Exception Handling
#include <exception>    // Base exception class
#include <stdexcept>    // Standard exceptions (e.g., std::runtime_error, std::logic_error)
#include <system_error> // System error exceptions

#ifdef CRLY_PLATFORM_WINDOWS
	#include <Windows.h>
#endif 
