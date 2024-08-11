# BigRed200 Research Project: CPU vs. GPU Efficiency

**Author:** Daeyeop Kim  
**Date:** 2023 December 
**Institution:** Luddy School of Informatics, Computing, and Engineering, Indiana University

## Abstract

As machine learning continues to grow in importance, GPU programming has become increasingly normalized. However, the complexity of GPU programming presents a significant challenge, leading to the development of many new packages and libraries that support GPU programming even for CPU-based machine learning programs. This project explores whether CPUs can be replaced by GPUs by examining their efficiency in performing deep learning tasks, specifically matrix transposition. Using BigRed 200, equipped with an NVIDIA Tesla A100 GPU and an AMD Epyc7713 CPU, the project compares the performance of these processors in transposing matrices of various sizes to determine the suitability of each for deep learning applications.

## Introduction

The GPU (Graphics Processing Unit) is designed for parallelizable problems and consists of numerous smaller, specialized cores that work together to deliver massive performance for tasks that can be divided and processed across many cores. Conversely, the CPU (Central Processing Unit) is the brain of the computer, managing multitasking, prioritizing tasks, and overseeing data processing. While both support parallel processing, the CPU can sometimes outperform the GPU depending on the application's nature and environment. This research project aims to determine which processor is more efficient in executing the deep learning process of transposing datasets and evaluate whether the CPU can replace the GPU.

## Methods

The experiment involves transposing matrices of varying sizes (512, 1024, 2048, and 4096) using both the CPU (AMD EPYC 7742) and GPU (NVIDIA A100) to compare their processing time and efficiency. The GPU transposing model uses different methods, including shmem and optimal models, to demonstrate enhanced efficiency. Each matrix size is transposed four times to record and analyze the results.

### Transpose Models:
- **Naive Method:** A basic approach to matrix transposition.
- **Shmem Model:** Utilizes SHMEM (Symmetric Hierarchical MEMory), a parallel programming library for low-latency distributed-memory supercomputers.
- **Optimal Model:** Implements optimized transposition techniques for better performance.

## Results

The results indicate a significant difference in processing time between the CPU and GPU, with the GPU demonstrating superior efficiency in matrix transposition across various sizes. The data confirms that for deep learning applications involving large datasets, the CPU cannot match the efficiency and memory handling capabilities of the GPU.

## Conclusion

The research demonstrates that there is a substantial gap in running time between the CPU and GPU when transposing matrices, highlighting the GPU's efficiency in handling large datasets typical in deep learning. The study concludes that CPUs cannot replace GPUs in terms of efficiency and memory management for deep learning tasks. Future research will explore the impact of temperature on CPU and GPU performance during processing.

## Future Work

Future research directions include examining the thermal dynamics of CPU and GPU operations to further understand their efficiency and potential improvements in cooling mechanisms or energy consumption.

## References
- **(For GPU Definition and CPU definition)
[https://www.intel.com/content/www/us/en/products/docs/processors/cpu-vs-gpu.html]
- **(why I transpose matrix can be show the difference between GPU and CPU)
[https://www.mathworks.com/discovery/deep-learning.html]
- **(Matrix Transpose with naive)
[https://en.wikipedia.org/wiki/In-place_matrix_transposition] 
- **(BigRed200 info)
[https://kb.iu.edu/d/brcc] 
- **(SHEM method)
[https://en.wikipedia.org/wiki/SHMEM] 




## Contact

For further inquiries, please contact Daeyeop Kim at [kdea989@gmail.com].
