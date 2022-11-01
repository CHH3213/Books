<h1> Examples </h1>

<!-- MarkdownTOC -->

- [1. Actual Examples](#1-actual-examples)
- [2. Abstract Examples](#2-abstract-examples)

<!-- /MarkdownTOC -->

## 1. Actual Examples

**E.g. 1** Deriving PCA by minimizing MSE.

- $\mathbf{X}=[\mathbf{x}_1~~~\mathbf{x}_2~~~\cdots~~~\mathbf{x}_n]_{m\times n}$, $\mathbf{x}_i$ is the $i$-th sample with m dimension. Assume for simplicity that $\mathbf{X}$ has zero mean.
- $\mathbf{W}=[\mathbf{w}_1~~~\mathbf{w}_2~~~\cdots~~~\mathbf{w}_k]_{m\times k}$, $\mathbf{w}_j$ is the $j$-th basis vector with m dimension.
- $\mathbf{Y}=\mathbf{W}^\top\mathbf{X}=[\mathbf{y}_1~~~\mathbf{y}_2~~~\cdots~~~\mathbf{y}_n]_{k\times n}$, $\mathbf{y}_i=\mathbf{W}^\top\mathbf{x}_i$ is the low dimension representation of $\mathbf{x}_i$.

The optimization problem of PCA is

\begin{align}
\underset{\mathbf{W}}{\operatorname{arg\,min}}\,\, & \|\mathbf{W}\mathbf{W}^\top \mathbf{X}-\mathbf{X}\|_\mathrm{F}^2 & & \\
\text{s.t.}\,\,\,\,\,\,\,\,                        & \mathbf{W}^\top\mathbf{W}=\mathbf{I}                             & & \text{orthogonal basis}\\
                                                   & \mathbf{Y}\mathbf{Y}^\top = \mathbf{\Lambda}.                    & & \mathbf{\Lambda} \text{ is a diagonal matrix, which means decorrelation}
\end{align}

We can simplify the above problem by using $\|\mathbf{W}\mathbf{W}^\top \mathbf{X}-\mathbf{X}\|_\mathrm{F}^2=\mathrm{tr}((\mathbf{W}\mathbf{W}^\top \mathbf{X}-\mathbf{X})^\top(\mathbf{W}\mathbf{W}^\top \mathbf{X}-\mathbf{X}))$ and $\mathbf{W}^\top\mathbf{W}=\mathbf{I}$, as

\begin{align*}
\underset{\mathbf{W}}{\operatorname{arg\,max}}\,\, & \mathrm{tr}(\mathbf{X}^\top\mathbf{W}\mathbf{W}^\top\mathbf{X}) \\
\text{s.t.}\,\,\,\,\,\,\,\,                        & \mathbf{W}^\top\mathbf{W}=\mathbf{I}\\
                                                   & \mathbf{Y}\mathbf{Y}^\top = \mathbf{\Lambda}.
\end{align*}

Introducing the Lagrange multipliers $\mathbf{\Sigma}_1=(\sigma_{1ij})_{k\times k}$ and $\mathbf{\Sigma}_2=(\sigma_{2ij})_{k\times k}$, the optimization problem is equivalent to

\begin{align*}
\underset{\mathbf{W},\mathbf{\Sigma}_1,\mathbf{\Sigma}_2}{\operatorname{arg\,max}}\,\, v & = \mathrm{tr}(\mathbf{X}^\top\mathbf{W}\mathbf{W}^\top\mathbf{X}) - \mathbf{1}^\top(\mathbf{\Sigma}_1\circ(\mathbf{W}^\top\mathbf{W}-\mathbf{I}))\mathbf{1}- \mathbf{1}^\top((\mathbf{\Sigma}_2\circ(\mathbf{1_{k\times k}}-\mathbf{I}))\circ\mathbf{Y}\mathbf{Y}^\top)\mathbf{1} & & \\
                                                                                         & =\mathrm{tr}(\mathbf{X}^\top\mathbf{W}\mathbf{W}^\top\mathbf{X})-\mathrm{tr}(\mathbf{\Sigma}_1^\top(\mathbf{W}^\top\mathbf{W}-\mathbf{I}))-\mathrm{tr}(\mathbf{\Sigma}_2'^\top\mathbf{Y}\mathbf{Y}^\top),                                                                         & &
\end{align*}

where we use $\mathbf{1}^\top(\mathbf{A}\circ\mathbf{B})\mathbf{1}=\mathrm{tr}(\mathbf{A}^\top\mathbf{B})$, and let $\mathbf{\Sigma}'_2=\mathbf{\Sigma}_2\circ(\mathbf{1_{k\times k}}-\mathbf{I})$.

***Next***, we will derive $\frac{\partial v}{\partial \mathbf{W}}$.

\begin{align*}
dv & =\mathrm{tr}(\mathbf{X}^\top(d\mathbf{W}\mathbf{W}^\top)\mathbf{X})-\mathrm{tr}(\mathbf{\Sigma}_1^\top d(\mathbf{W}^\top\mathbf{W}))-\mathrm{tr}(\mathbf{\Sigma}_2'^\top d(\mathbf{Y}\mathbf{Y}^\top))\\
   & =\mathrm{tr}(\mathbf{X}^\top(d(\mathbf{W})\mathbf{W}^\top+\mathbf{W}d(\mathbf{W}^\top))\mathbf{X})-\mathrm{tr}(\mathbf{\Sigma}_1^\top (d(\mathbf{W}^\top)\mathbf{W}+\mathbf{W}^\top d\mathbf{W}))-\mathrm{tr}(\mathbf{\Sigma}_2'^\top (d(\mathbf{Y})\mathbf{Y}^\top+\mathbf{Y}d(\mathbf{Y}^\top)))\\
   & =\mathrm{tr}(2\mathbf{W}^\top \mathbf{X}\mathbf{X}^\top d\mathbf{W})-\mathrm{tr}((\mathbf{\Sigma}_1+\mathbf{\Sigma}_1^\top)\mathbf{W}^\top d\mathbf{W})-\mathrm{tr}(\mathbf{Y}^\top(\mathbf{\Sigma}_2'+\mathbf{\Sigma}_2'^\top)d\mathbf{Y})\\
   & =\mathrm{tr}(2\mathbf{W}^\top \mathbf{X}\mathbf{X}^\top d\mathbf{W})-\mathrm{tr}((\mathbf{\Sigma}_1+\mathbf{\Sigma}_1^\top)\mathbf{W}^\top d\mathbf{W})-\mathrm{tr}(\mathbf{X}^\top\mathbf{W}(\mathbf{\Sigma}_2'+\mathbf{\Sigma}_2'^\top)(d\mathbf{\mathbf{W}^\top)\mathbf{X}})\\
   & =\mathrm{tr}(2\mathbf{W}^\top \mathbf{X}\mathbf{X}^\top d\mathbf{W})-\mathrm{tr}((\mathbf{\Sigma}_1+\mathbf{\Sigma}_1^\top)\mathbf{W}^\top d\mathbf{W})-\mathrm{tr}((\mathbf{\Sigma}_2'+\mathbf{\Sigma}_2'^\top)\mathbf{W}^\top\mathbf{X}\mathbf{X}^\top d\mathbf{\mathbf{W}}).\\
\end{align*}

Therefore $\frac{\partial v}{\partial \mathbf{W}}=2\mathbf{W}^\top \mathbf{X}\mathbf{X}^\top-(\mathbf{\Sigma}_1+\mathbf{\Sigma}_1^\top)\mathbf{W}^\top-(\mathbf{\Sigma}_2'+\mathbf{\Sigma}_2'^\top)\mathbf{W}^\top\mathbf{X}\mathbf{X}^\top$. Let it be $\mathbf{0}$, we get

\begin{align*}
\mathbf{X}\mathbf{X}^\top\mathbf{W}=\mathbf{W}(\frac{\mathbf{\Sigma}_1+\mathbf{\Sigma}_1^\top}{2})(\mathbf{I}-\frac{\mathbf{\Sigma}_2'+\mathbf{\Sigma}_2'^\top}{2})^{-1}.
\end{align*}

Left multiply the equation by $\mathbf{W}^\top$ and use eq. (2) - $\mathbf{W}^\top\mathbf{W}=\mathbf{I}$ and eq. (3) - $\mathbf{Y}\mathbf{Y}^\top =\mathbf{W}^\top\mathbf{X}\mathbf{X}^\top\mathbf{W}=\mathbf{\Lambda}$, we get

\begin{align}
\setcounter{equation}{3}
                & & \mathbf{X}\mathbf{X}^\top\mathbf{W}                                                                                              & =\mathbf{W}\mathbf{\Lambda}\\
\Leftrightarrow & & [\mathbf{X}\mathbf{X}^\top\mathbf{w}_1~~~\mathbf{X}\mathbf{X}^\top\mathbf{w}_2~~~\cdots~~~\mathbf{X}\mathbf{X}^\top\mathbf{w}_k] & =[\lambda_1\mathbf{w}_1~~~\lambda_1\mathbf{w}_2~~~\cdots~~~\lambda_k\mathbf{w}_k]\nonumber\\
\Leftrightarrow & & \mathbf{X}\mathbf{X}^\top\mathbf{w}_j                                                                                            & =\lambda_j \mathbf{w}_j,~j=1,2,\cdots,k,\nonumber
\end{align}

from which we can see ***$\lambda_j$ is the eigenvalue of $\mathbf{X}\mathbf{X}^\top$ and $\mathbf{w}_j$ is the corresponding eigenvector***.

Substitute eq. (4) into eq. (1),

\begin{align*}
  & \operatorname{arg\,max}\,\, \mathrm{tr}(\mathbf{X}^\top\mathbf{W}\mathbf{W}^\top\mathbf{X})& &\\
= & \operatorname{arg\,max}\,\, \mathrm{tr}(\mathbf{X}\mathbf{X}^\top\mathbf{W}\mathbf{W}^\top)& &\\
= & \operatorname{arg\,max}\,\, \mathrm{tr}(\mathbf{W}\mathbf{\Lambda}\mathbf{W}^\top)& & \text{from eq. (4)}\\
= & \operatorname{arg\,max}\,\, \mathrm{tr}(\mathbf{W}^\top\mathbf{W}\mathbf{\Lambda})& &\\
= & \operatorname{arg\,max}\,\, \mathrm{tr}(\mathbf{\Lambda})& & \text{from eq. (2)}\\
=& \operatorname{arg\,max}\,\, \lambda_1 + \lambda_2 + \cdots + \lambda_k,
\end{align*}

therefore ***$\lambda_1$, $\lambda_2$, ..., $\lambda_k$ should be the largest k eigenvalues***. $\blacksquare$



## 2. Abstract Examples

**E.g. 1**, $\frac{d(z(\mathbf{y}(\mathbf{X})))}{d\mathbf{X}}$, where $\mathbf{X}$ is a $p\times q$ matrix.

\begin{align*}
\frac{dz}{d\mathbf{X}} & =
\begin{bmatrix}
\frac{\partial z}{\partial x_{11}} & \frac{\partial z}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial x_{p1}}\\
\frac{\partial z}{\partial x_{12}} & \frac{\partial z}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial x_{p2}}\\
\vdots                             & \vdots                             & \ddots & \vdots\\
\frac{\partial z}{\partial x_{1q}} & \frac{\partial z}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial x_{pq}}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{11}} & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{p1}}\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{12}} & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{p2}}\\
\vdots                                                                            & \vdots                                                                            & \ddots & \vdots\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{1q}} & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{pq}}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{:1}}\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{:2}}\\
\vdots\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{:q}}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{y}} & \mathbf{0}                             & \cdots & \mathbf{0}\\
\mathbf{0}                             & \frac{\partial z}{\partial \mathbf{y}} & \cdots & \mathbf{0}\\
\vdots                                 & \vdots                                 & \ddots & \vdots\\
\mathbf{0}                             & \mathbf{0}                             & \cdots & \frac{\partial z}{\partial \mathbf{y}}   \\
\end{bmatrix}
\begin{bmatrix}
\frac{\partial \mathbf{y}}{\partial x_{:1}}\\
\frac{\partial \mathbf{y}}{\partial x_{:2}}\\
\vdots\\
\frac{\partial \mathbf{y}}{\partial x_{:q}}\\
\end{bmatrix}\\
& =
(\mathbf{I}_{q\times q}\otimes \frac{\partial z}{\partial \mathbf{y}})
\begin{bmatrix}
\frac{\partial \mathbf{y}}{\partial x_{:1}}\\
\frac{\partial \mathbf{y}}{\partial x_{:2}}\\
\vdots\\
\frac{\partial \mathbf{y}}{\partial x_{:q}}\\
\end{bmatrix},
\end{align*}

or

\begin{align*}
\frac{dz}{d\mathbf{X}} & =
\begin{bmatrix}
\frac{\partial z}{\partial x_{11}} & \frac{\partial z}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial x_{p1}}\\
\frac{\partial z}{\partial x_{12}} & \frac{\partial z}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial x_{p2}}\\
\vdots                             & \vdots                             & \ddots & \vdots\\
\frac{\partial z}{\partial x_{1q}} & \frac{\partial z}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial x_{pq}}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{11}} & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{p1}}\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{12}} & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{p2}}\\
\vdots                                                                            & \vdots                                                                            & \ddots & \vdots\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{1q}} & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{pq}}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
(\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{1:}})^\top&
(\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{2:}})^\top&
\cdots&
(\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{p:}})^\top
\end{bmatrix}\\
& =
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{1:}}\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{2:}}\\
\vdots\\
\frac{\partial z}{\partial \mathbf{y}}\frac{\partial \mathbf{y}}{\partial x_{p:}}
\end{bmatrix}^\top\\
& =
((\mathbf{I}_{p\times p}\otimes \frac{\partial z}{\partial \mathbf{y}})
\begin{bmatrix}
\frac{\partial \mathbf{y}}{\partial x_{1:}}\\
\frac{\partial \mathbf{y}}{\partial x_{2:}}\\
\vdots\\
\frac{\partial \mathbf{y}}{\partial x_{p:}}\\
\end{bmatrix})^\top.
\end{align*}

In the above, we haven't used any differential technique, because we haven't defined the derivative of vector-by-matrix $\frac{d \mathbf{y}}{d\mathbf{X}}$ which could be a 3D tensor. However, in some cases such as $\mathbf{y}=\mathbf{W}\mathbf{x}$ (w.r.t. $\mathbf{W}$), the differential technique still works (see [this example](./README.md#y=Wx)).

**E.g. 2**, $\frac{d(z(\mathbf{Y}(\mathbf{X})))}{d\mathbf{X}}$, where $\mathbf{Y}$ is a $m\times n$ matrix and $\mathbf{X}$ is a $p\times q$ matrix.

\begin{align*}
\frac{dz}{d\mathbf{X}} & =
\begin{bmatrix}
\frac{\partial z}{\partial x_{11}} & \frac{\partial z}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial x_{p1}}\\
\frac{\partial z}{\partial x_{12}} & \frac{\partial z}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial x_{p2}}\\
\vdots                             & \vdots                             & \ddots & \vdots\\
\frac{\partial z}{\partial x_{1q}} & \frac{\partial z}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial x_{pq}}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
\mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{11}})\mathbf{1}_{n} & \mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{21}})\mathbf{1}_{n} & \cdots & \mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p1}})\mathbf{1}_{n}\\
\mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{12}})\mathbf{1}_{n} & \mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{22}})\mathbf{1}_{n} & \cdots & \mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p2}})\mathbf{1}_{n}\\
\vdots & \vdots & \ddots & \vdots\\
\mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{1q}})\mathbf{1}_{n} & \mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{2q}})\mathbf{1}_{n} & \cdots & \mathbf{1}_{m}^\top(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{pq}})\mathbf{1}_{n}\\
\end{bmatrix}\\
& =
\begin{bmatrix}
\mathbf{1}_{m}^\top\small
\begin{bmatrix}
(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{11}})\mathbf{1}_{n} & (\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{21}})\mathbf{1}_{n} & \cdots & (\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p1}})\mathbf{1}_{n}\\
\end{bmatrix}\\
\mathbf{1}_{m}^\top\small
\begin{bmatrix}
(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{12}})\mathbf{1}_{n} & (\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{22}})\mathbf{1}_{n} & \cdots & (\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p2}})\mathbf{1}_{n}\\
\end{bmatrix}\\
\vdots\\
\mathbf{1}_{m}^\top\small
\begin{bmatrix}
(\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{1q}})\mathbf{1}_{n} & (\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{2q}})\mathbf{1}_{n} & \cdots & (\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{pq}})\mathbf{1}_{n}\\
\end{bmatrix}
\end{bmatrix}\\
& =
\begin{bmatrix}
\mathbf{1}_{m}^\top\small
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{11}} & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p1}}\\
\end{bmatrix}
(\mathbf{I}_{p\times p}\otimes \mathbf{1}_{n})\\
\mathbf{1}_{m}^\top\small
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{12}} & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p2}}\\
\end{bmatrix}
(\mathbf{I}_{p\times p}\otimes \mathbf{1}_{n})\\
\vdots\\
\mathbf{1}_{m}^\top\small
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{1q}} & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{pq}}\\
\end{bmatrix}
(\mathbf{I}_{p\times p}\otimes \mathbf{1}_{n})
\end{bmatrix}\\
& =
(\mathbf{I}_{q\times q}\otimes \mathbf{1}_{m}^\top)
\begin{bmatrix}
\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{11}} & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{21}} & \cdots & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p1}}\\
\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{12}} & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{22}} & \cdots & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{p2}}\\
\vdots                                                                                     & \vdots                                                                                     & \ddots & \vdots\\
\frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{1q}} & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{2q}} & \cdots & \frac{\partial z}{\partial \mathbf{Y}^\top}\circ\frac{\partial\mathbf{Y}}{\partial x_{pq}}
\end{bmatrix}
(\mathbf{I}_{p\times p}\otimes \mathbf{1}_{n})\\
& =
(\mathbf{I}_{q\times q}\otimes \mathbf{1}_{m}^\top)
((\mathbf{1}_{q\times p}\otimes \frac{\partial z}{\partial \mathbf{Y}^\top})\circ\begin{bmatrix}
\frac{\partial\mathbf{Y}}{\partial x_{11}} & \frac{\partial\mathbf{Y}}{\partial x_{21}} & \cdots & \frac{\partial\mathbf{Y}}{\partial x_{p1}}\\
\frac{\partial\mathbf{Y}}{\partial x_{12}} & \frac{\partial\mathbf{Y}}{\partial x_{22}} & \cdots & \frac{\partial\mathbf{Y}}{\partial x_{p2}}\\
\vdots                                     & \vdots                                     & \ddots & \vdots\\
\frac{\partial\mathbf{Y}}{\partial x_{1q}} & \frac{\partial\mathbf{Y}}{\partial x_{2q}} & \cdots & \frac{\partial\mathbf{Y}}{\partial x_{pq}}
\end{bmatrix})
(\mathbf{I}_{p\times p}\otimes \mathbf{1}_{n}).
\end{align*}

In the above, we haven't used any differential technique, because we haven't defined the derivative of matrix-by-matrix $\frac{d \mathbf{Y}}{d\mathbf{X}}$ which could be a 4D tensor. However, in some cases such as $\mathbf{Y}=\mathbf{A}\mathbf{X}$, the differential technique still works (see [this example](./README.md#Y=AX)). Besides, there is another excellent example of $\frac{d(z(\mathbf{Y}(\mathbf{X})))}{d\mathbf{X}}$: derivative of SVD - https://arxiv.org/pdf/1509.07838.pdf.