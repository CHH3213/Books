*read \*.md, do not read \*.tex.md*

<h1> <p align="center"> Matrix Calculus </p> </h1>

In this page, we introduce a differential based method for vector and matrix derivatives (matrix calculus), which ***only needs a few simple rules to derive most matrix derivatives***. This method is useful and well established in mathematics; however, few documents clearly or detailedly describe it. Therefore, we make this page aiming at the comprehensive introduction of ***matrix calculus via differentials***.

\* *If you want results only, there is an awesome online tool [Matrix Calculus](http://www.matrixcalculus.org/). If you want "how to," let's get started.*

<!-- MarkdownTOC -->

- [0. Notation](#0-notation)
- [1. Matrix Calculus via Differentials](#1-matrix-calculus-via-differentials)
    * [1.1 Differential Identities](#11-differential-identities)
    * [1.2 Deriving Matrix Derivatives](#12-deriving-matrix-derivatives)
        + [1.2.1 Abstract examples: repeat identities 1](#121-abstract-examples-repeat-identities-1)
        + [1.2.2 Actual examples: assisted by identities 2](#122-actual-examples-assisted-by-identities-2)
- [2. Conclusion](#2-conclusion)

<!-- /MarkdownTOC -->


## 0. Notation

- $x$, $\mathbf{x}$, and $\mathbf{X}$ denote $scalar$, $\mathbf{vector}$, and $\mathbf{MATRIX}$ respectively.
- The first half of the alphabet $(a, b, c, \cdots)$ denote constants, and the second half $(t, x, y, \cdots)$ denote variables.
- $\mathbf{X}^\top$ denotes matrix transpose, $\mathrm{tr}(\mathbf{X})$ is the trace, $|\mathbf{X}|$ is the determinant, and $adj(\mathbf{X})$ is the adjugate matrix.
- $\otimes$ is the Kronecker product and $\circ$ is the Hadamard product.
- Here we use ***numerator layout***, while the online tool [Matrix Calculus](http://www.matrixcalculus.org/) seems to use ***mixed layout***. Please refer to [Wiki - Matrix Calculus - Layout Conventions](https://en.wikipedia.org/wiki/Matrix_calculus#Layout_conventions) for the detailed layout definitions, and keep in mind that ***different layouts lead to different results***. Below is the numerator layout,

\begin{align*}
\frac{dy}{d\mathbf{x}} =
\left[
\frac{\partial y}{\partial x_1}
\frac{\partial y}{\partial x_2}
\cdots
\frac{\partial y}{\partial x_n}
\right],
\end{align*}

\begin{align*}
\frac{d\mathbf{y}}{dx} =
\begin{bmatrix}
\frac{\partial y_1}{\partial x}\\
\frac{\partial y_2}{\partial x}\\
\vdots\\
\frac{\partial y_m}{\partial x}\\
\end{bmatrix},
\end{align*}

\begin{align*}
\frac{d\mathbf{y}}{d\mathbf{x}} =
\begin{bmatrix}
\frac{\partial y_1}{\partial x_1} & \frac{\partial y_1}{\partial x_2} & \cdots & \frac{\partial y_1}{\partial x_n}\\
\frac{\partial y_2}{\partial x_1} & \frac{\partial y_2}{\partial x_2} & \cdots & \frac{\partial y_2}{\partial x_n}\\
\vdots & \vdots & \ddots & \vdots\\
\frac{\partial y_m}{\partial x_1} & \frac{\partial y_m}{\partial x_2} & \cdots & \frac{\partial y_m}{\partial x_n}\\
\end{bmatrix},
\end{align*}

\begin{align*}
\frac{dy}{d\mathbf{X}} =
\begin{bmatrix}
\frac{\partial y}{\partial x_{11}} & \frac{\partial y}{\partial x_{21}} & \cdots & \frac{\partial y}{\partial x_{p1}}\\
\frac{\partial y}{\partial x_{12}} & \frac{\partial y}{\partial x_{22}} & \cdots & \frac{\partial y}{\partial x_{p2}}\\
\vdots & \vdots & \ddots & \vdots\\
\frac{\partial y}{\partial x_{1q}} & \frac{\partial y}{\partial x_{2q}} & \cdots & \frac{\partial y}{\partial x_{pq}}\\
\end{bmatrix}.
\end{align*}


## 1. Matrix Calculus via Differentials

### 1.1 Differential Identities

- **Identities 1**

\begin{align}
dy&=\frac{dy}{dx}dx\\
dy&=\frac{dy}{d\mathbf{x}}d\mathbf{x}\\
dy&=\mathrm{tr}(\frac{dy}{d\mathbf{X}}d\mathbf{X})\\
d\mathbf{y}&=\frac{d\mathbf{y}}{dx}dx\\
d\mathbf{y}&=\frac{d\mathbf{y}}{d\mathbf{x}}d\mathbf{x}\\
d\mathbf{Y}&=\frac{d\mathbf{Y}}{dx}dx
\end{align}

- **Identities 2**

\begin{align}
\setcounter{equation}{6}
d\mathbf{A}&=\mathbf{0}\\
d(a\mathbf{X})&=a~d\mathbf{X}\\
d(\mathbf{X+Y})&=d\mathbf{X}+d\mathbf{Y}\\
d({\mathbf{X}\mathbf{Y}})&=(d\mathbf{X})\mathbf{Y}+\mathbf{X}(d\mathbf{Y})\\
d({\mathbf{X_1}\mathbf{X_2}\cdots\mathbf{X_n}})&=(d\mathbf{X_1})\mathbf{X_2}\cdots\mathbf{X_n}+\mathbf{X_1}(d\mathbf{X_2})\cdots\mathbf{X_n}+\cdots+\mathbf{X_1}\mathbf{X_2}\cdots (d\mathbf{X_n})\\
d({\mathbf{A}\mathbf{X}}\mathbf{B}+\mathbf{C})&=\mathbf{A}(d\mathbf{X})\mathbf{B}\\
d({\mathbf{X}\otimes\mathbf{Y}})&=(d\mathbf{X})\otimes\mathbf{Y}+\mathbf{X}\otimes(d\mathbf{Y})\\
d({\mathbf{X}\circ\mathbf{Y}})&=(d\mathbf{X})\circ\mathbf{Y}+\mathbf{X}\circ(d\mathbf{Y})\\
d(\mathbf{X}^\top )&=(d\mathbf{X})^\top\\
d(\mathbf{X}^{-1})&=-\mathbf{X}^{-1}(d\mathbf{X})\mathbf{X}^{-1}\\
d(\mathrm{tr}(\mathbf{X}))&=\mathrm{tr}(d\mathbf{X})\\
d(|\mathbf{X}|)&=\mathrm{tr}(adj(\mathbf{X})d\mathbf{X})=|\mathbf{X}|\mathrm{tr}(\mathbf{X}^{-1}d\mathbf{X})
\end{align}

- **Identities 1.5 - total differential**. Actually, all identities 1 are the matrix form of the total differential in eq. (19).

\begin{align}
\setcounter{equation}{18}
df(x,y,z)&=\frac{\partial f}{\partial x}dx+\frac{\partial f}{\partial y}dy+\frac{\partial f}{\partial z}dz\\
df(x,\mathbf{y},\mathbf{Z})&=\frac{\partial f}{\partial x}dx+\frac{\partial f}{\partial \mathbf{y}}d\mathbf{y}+\mathrm{tr}(\frac{\partial f}{\partial \mathbf{Z}}d\mathbf{Z})\\
d\mathbf{f}(x,\mathbf{y})&=\frac{\partial \mathbf{f}}{\partial x}dx+\frac{\partial \mathbf{f}}{\partial \mathbf{y}}d\mathbf{y}\\
d\mathbf{F}(x,y,z)&=\frac{\partial \mathbf{F}}{\partial x}dx+\frac{\partial \mathbf{F}}{\partial y}dy+\frac{\partial \mathbf{F}}{\partial z}dz
\end{align}

### 1.2 Deriving Matrix Derivatives

To derive a matrix derivative, we ***repeat using the identities 1 (the process is actually a chain rule)*** assisted by identities 2.

#### 1.2.1 Abstract examples: repeat identities 1

**E.g. 1**, $\frac{d(z(\mathbf{y}(\mathbf{x})))}{d\mathbf{x}}$.

\begin{align*}
dz & =\frac{dz}{d\mathbf{y}}d\mathbf{y}                                 & & \text{from eq. (2)}\\
   & =\frac{dz}{d\mathbf{y}}\frac{d\mathbf{y}}{d\mathbf{x}}d\mathbf{x}, & & \text{from eq. (5)}
\end{align*}

finally from eq. (2), we get $\frac{dz}{d\mathbf{x}}=\frac{dz}{d\mathbf{y}}\frac{d\mathbf{y}}{d\mathbf{x}}$.

**E.g. 2**, $\frac{d(z(y(\mathbf{X})))}{d\mathbf{X}}$.

\begin{align*}
dz & =\frac{dz}{dy}dy                                              & & \text{from eq. (1)}\\
   & =\frac{dz}{dy}\mathrm{tr}(\frac{dy}{d\mathbf{X}}d\mathbf{X})  & & \text{from eq. (3)}\\
   & =\mathrm{tr}(\frac{dz}{dy}\frac{dy}{d\mathbf{X}}d\mathbf{X}), & &
\end{align*}

finally from eq. (3), we get $\frac{dz}{d\mathbf{X}}=\frac{dz}{dy}\frac{dy}{d\mathbf{X}}$.

**E.g. 3**, $\frac{d(z(\mathbf{Y}(x)))}{dx}$.

\begin{align*}
dz & =\mathrm{tr}(\frac{dz}{d\mathbf{Y}}d\mathbf{Y})               & & \text{from eq. (3)}\\
   & =\mathrm{tr}(\frac{dz}{d\mathbf{Y}}\frac{d\mathbf{Y}}{dx}dx)  & & \text{from eq. (6)}\\
   & =\mathrm{tr}(\frac{dz}{d\mathbf{Y}}\frac{d\mathbf{Y}}{dx})dx, & &
\end{align*}

finally from eq. (1), we get $\frac{dz}{dx}=\mathrm{tr}(\frac{dz}{d\mathbf{Y}}\frac{d\mathbf{Y}}{x})$.

**E.g. 4**, $\frac{d(\mathbf{z}(\mathbf{y}(\mathbf{x})))}{d\mathbf{x}}$.

\begin{align*}
d\mathbf{z} & =\frac{d\mathbf{z}}{d\mathbf{y}}d\mathbf{y}                                 & & \text{from eq. (5)}\\
            & =\frac{d\mathbf{z}}{d\mathbf{y}}\frac{d\mathbf{y}}{d\mathbf{x}}d\mathbf{x}, & & \text{from eq. (5)}\\
\end{align*}

finally from eq. (5), we get $\frac{d\mathbf{z}}{d\mathbf{x}}=\frac{d\mathbf{z}}{d\mathbf{y}}\frac{d\mathbf{y}}{d\mathbf{x}}$.

#### 1.2.2 Actual examples: assisted by identities 2

**E.g. 1**, $\frac{d(\mathbf{x}^\top \mathbf{x})}{d\mathbf{x}}$.

\begin{align*}
d(\mathbf{x}^\top \mathbf{x}) & =d(\mathbf{x}^\top )\mathbf{x}+\mathbf{x}^\top d\mathbf{x} & & \text{from eq. (10)}\\
                              & =(d\mathbf{x})^\top \mathbf{x}+\mathbf{x}^\top d\mathbf{x} & & \text{from eq. (15)}\\
                              & =\mathbf{x}^\top d\mathbf{x} + \mathbf{x}^\top d\mathbf{x} & & \text{from } \mathbf{x}^\top \mathbf{y}=\mathbf{y}^\top \mathbf{x}\\
                              & =2\mathbf{x}^\top d\mathbf{x},                             & &
\end{align*}

finally from eq. (2), we get $\frac{d(\mathbf{x}^\top \mathbf{x})}{d\mathbf{x}}=2\mathbf{x}^\top$.

<a name="y=Wx"></a>**E.g. 2**, $\frac{d||\mathbf{W}\mathbf{x}+\mathbf{b}||_2^2}{d\mathbf{W}}$.

\begin{align*}
d(||\mathbf{W}\mathbf{x}+\mathbf{b}||_2^2) & =d((\mathbf{W}\mathbf{x}+\mathbf{b})^\top (\mathbf{W}\mathbf{x}+\mathbf{b}))                                   & & \\
                                           & =d(\mathbf{y}^\top \mathbf{y})\Big|_{\mathbf{y}=\mathbf{W}\mathbf{x}+\mathbf{b}}                               & & \\
                                           & =\frac{d(\mathbf{y}^\top\mathbf{y})}{d\mathbf{y}}d\mathbf{y}\Big|_{\mathbf{y}=\mathbf{W}\mathbf{x}+\mathbf{b}} & & \text{from eq. (2)}\\
                                           & =2\mathbf{y}^\top d\mathbf{y}\Big|_{\mathbf{y}=\mathbf{W}\mathbf{x}+\mathbf{b}}                                & & \text{from e.g. 1, } \frac{d\mathbf{x}^\top \mathbf{x}}{d\mathbf{x}}=2\mathbf{x}^\top\\
                                           & =2(\mathbf{W}\mathbf{x}+\mathbf{b})^\top d(\mathbf{W}\mathbf{x}+\mathbf{b})                                    & & \\
                                           & =2(\mathbf{W}\mathbf{x}+\mathbf{b})^\top (d\mathbf{W})\mathbf{x}                                               & & \text{from eq. (12)}\\
                                           & =\mathrm{tr}(2(\mathbf{W}\mathbf{x}+\mathbf{b})^\top (d\mathbf{W})\mathbf{x})                                  & & \text{from } x=\mathrm{tr}(x)\\
                                           & =\mathrm{tr}(2\mathbf{x}(\mathbf{W}\mathbf{x}+\mathbf{b})^\top d\mathbf{W}),                                   & & \text{from } \mathrm{tr}(\mathbf{ABC})=\mathrm{tr}(\mathbf{BCA})=\mathrm{tr}(\mathbf{CAB})
\end{align*}

finally from eq. (3), we get $\frac{d||\mathbf{W}\mathbf{x}+\mathbf{b}||_2^2}{d\mathbf{W}}=2\mathbf{x}(\mathbf{W}\mathbf{x}+\mathbf{b})^\top$. From line 3 to 4, we use the conclusion of $\frac{d\mathbf{x}^\top \mathbf{x}}{d\mathbf{x}}=2\mathbf{x}^\top$, that is to say, we can derive more complicated  matrix derivatives by properly utilizing the existing ones. From line 6 to 7, we use $x=\mathrm{tr}(x)$ to introduce the $\mathrm{tr(\cdot)}$ in order to use eq. (3) later, which is common in scalar-by-matrix derivatives.

**E.g. 3**, $\frac{d(\ln|\mathbf{X}|)}{d\mathbf{X}}$.

\begin{align*}
d(\ln|\mathbf{X}|) & =|\mathbf{X}|^{-1}d(|\mathbf{X}|)                                     & & \text{from eq. (1)}\\
                   & =|\mathbf{X}|^{-1}|\mathbf{X}|\mathrm{tr}(\mathbf{X}^{-1}d\mathbf{X}) & & \text{from eq. (18)}\\
                   & =\mathrm{tr}(\mathbf{X}^{-1}d\mathbf{X}),                             & &
\end{align*}

finally from eq. (3), we get $\frac{d(\ln|\mathbf{X}|)}{d\mathbf{X}}=\mathbf{X}^{-1}$.

<a name="Y=AX"></a>**E.g. 4**, $\frac{d(\mathrm{tr}(\mathbf{A}\mathbf{X}\mathbf{B}))}{d\mathbf{X}}$.

\begin{align*}
d(\mathrm{tr}(\mathbf{A}\mathbf{X}\mathbf{B})) & =\mathrm{tr}(d(\mathbf{A}\mathbf{X}\mathbf{B})) & & \text{from eq. (17)}\\
                                               & =\mathrm{tr}(\mathbf{A}(d\mathbf{X})\mathbf{B}) & & \text{from eq. (12)}\\
                                               & =\mathrm{tr}(\mathbf{B}\mathbf{A}d\mathbf{X}),  & & \text{from } \mathrm{tr}(\mathbf{ABC})=\mathrm{tr}(\mathbf{BCA})=\mathrm{tr}(\mathbf{CAB})
\end{align*}

finally from eq. (3), we get $\frac{d(\mathrm{tr}(\mathbf{A}\mathbf{X}\mathbf{B}))}{d\mathbf{X}}=\mathbf{B}\mathbf{A}$.

**E.g. 5 - two layer neural network**, $l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))$, $l$ is a loss function such as Softmax Cross Entropy and MSE, $\sigma$ is an element-wise activation function such as Sigmoid and ReLU.

For $\frac{\partial l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))}{\partial \mathbf{W}_2}$,

\begin{align*}
d(l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))) & =\frac{d(l(\mathbf{y}))}{d\mathbf{y}}d(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))     & & \text{from eq. (2), and let } \mathbf{y}=\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x})\\
                                                 & =\frac{d(l(\mathbf{y}))}{d\mathbf{y}}d(\mathbf{W}_2)\sigma(\mathbf{W}_1\mathbf{x})     & & \text{from eq. (12)}\\
                                                 & =tr(\frac{d(l(\mathbf{y}))}{d\mathbf{y}}d(\mathbf{W}_2)\sigma(\mathbf{W}_1\mathbf{x})) & & \text{from } x=\mathrm{tr}(x)\\
                                                 & =tr(\sigma(\mathbf{W}_1\mathbf{x})\frac{d(l(\mathbf{y}))}{d\mathbf{y}}d\mathbf{W}_2),  & & \text{from } \mathrm{tr}(\mathbf{ABC})=\mathrm{tr}(\mathbf{BCA})=\mathrm{tr}(\mathbf{CAB})
\end{align*}

finally from eq. (3), we get $\frac{\partial l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))}{\partial \mathbf{W}_2}=\sigma(\mathbf{W}_1\mathbf{x})\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\Big|_{\mathbf{y}=\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x})}$.

For $\frac{\partial l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))}{\partial \mathbf{W}_1}$,

\begin{align*}
d(l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))) & =\frac{d(l(\mathbf{y}))}{d\mathbf{y}}d(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))                                                    & & \text{from eq. (2), and let } \mathbf{y}=\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x})\\
                                                 & =\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2d(\sigma(\mathbf{W}_1\mathbf{x}))                                                    & & \text{from eq. (12)}\\
                                                 & =\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2[\sigma'(\mathbf{W}_1\mathbf{x})\circ d(\mathbf{W}_1\mathbf{x})]                     & & \text{from } d(\sigma(\mathbf{x}))=\sigma'(\mathbf{x})\circ d\mathbf{x}\\
                                                 & =\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2[\sigma'(\mathbf{W}_1\mathbf{x})\circ (d(\mathbf{W}_1)\mathbf{x})]                   & & \text{from eq. (12)}\\
                                                 & =[(\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2)^\top\circ\sigma'(\mathbf{W}_1\mathbf{x})]^\top d(\mathbf{W}_1)\mathbf{x}         & & \text{from } \mathbf{x}^\top(\mathbf{y}\circ\mathbf{z})=(\mathbf{x}\circ\mathbf{y})^\top\mathbf{z}\\
                                                 & =[(\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2)\circ\sigma'(\mathbf{W}_1\mathbf{x})^\top] d(\mathbf{W}_1)\mathbf{x}              & & \\
                                                 & =\mathrm{tr}([(\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2)\circ\sigma'(\mathbf{W}_1\mathbf{x})^\top] d(\mathbf{W}_1)\mathbf{x}) & & \text{from } x=\mathrm{tr}(x)\\
                                                 & =\mathrm{tr}(\mathbf{x}[(\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2)\circ\sigma'(\mathbf{W}_1\mathbf{x})^\top] d\mathbf{W}_1),  & & \text{from } \mathrm{tr}(\mathbf{ABC})=\mathrm{tr}(\mathbf{BCA})=\mathrm{tr}(\mathbf{CAB})
\end{align*}

finally from eq. (3), we get $\frac{\partial l(\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x}))}{\partial \mathbf{W}_1}=\mathbf{x}[(\frac{d(l(\mathbf{y}))}{d\mathbf{y}}\mathbf{W}_2)\circ\sigma'(\mathbf{W}_1\mathbf{x})^\top]\Big|_{\mathbf{y}=\mathbf{W}_2\sigma(\mathbf{W}_1\mathbf{x})}$.

**E.g. 6**, prove $d(\mathbf{X}^{-1})=-\mathbf{X}^{-1}(d\mathbf{X})\mathbf{X}^{-1}$.

Since

\begin{align*}
\mathbf{X}^{-1}\mathbf{X}=\mathbf{I},
\end{align*}

then

\begin{align*}
d(\mathbf{X}^{-1}\mathbf{X})=d(\mathbf{X}^{-1})\mathbf{X} + \mathbf{X}^{-1}d\mathbf{X}=\mathbf{0},
\end{align*}

therefore

\begin{align*}
d(\mathbf{X}^{-1})=-\mathbf{X}^{-1}(d\mathbf{X})\mathbf{X}^{-1}.
\end{align*}

\* *See [examples.md](./examples.md) for more examples.*


## 2. Conclusion
Now, if we fully understand the core mind of the above examples, I believe we can derive most matrix derivatives in [Wiki - Matrix Calculus](https://en.wikipedia.org/wiki/Matrix_calculus) by ourself. Please correct me if there is any mistake, and raise issues to request the detailed steps of computing the matrix derivatives that you are interested in.
