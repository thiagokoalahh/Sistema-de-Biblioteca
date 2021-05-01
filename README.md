# Sistema de Biblioteca

Trabalho final da matéria de 'Informática Aplicada' de quando estava no último ano do ensino médio no IFES, curso: Eletrotécnica.

## Enunciado do trabalho

Defina uma estrutura de registros para controle do acervo de uma biblioteca, defina no máximo 100 livros como acervo da biblioteca. Cada registro de livro deverá conter: isbn, titulo do livro, editora, autor, area(número da área) , ano, quantidade de cópias e quantidade emprestada, empréstimo acumulado.

A area que o livro pertence deverá estar em um vetor específico onde cada posição deverá conter a identificação da área em string, são previstos 10 áreas ou seja, um vetor de 10 posições: Literatura, História, Administração, Engenharia entre outros.

Na inclusão de cada livro deve ser informado todos os dados do registro exceto quantidade emprestada e o empréstimo acumulado que iniciarão sempre como 0; Lembrando que para área deve ser informado o número da área.

Os campo Quantidade Emprestada e Empréstimo Acumulado serão atualizadas quando o livro for emprestado, porém a Quantidade Emprestada é atualizado (decrementando) quando o empréstimo é devolvido enquanto o empréstimo acumulado nunca será decrementado.

Defina funções para:

* Cadastrar as 10 Áreas (esta função não deverá estar no MENU) mas será chamada no MAIN para iniciar o sistema;

---

1. Exibir as 10 Áreas;

2. Inserir um Livro (informar todos os campos do registro exceto quantidade emprestada e empréstimo acumulado) ao informar o número da área deverá exibir o nome da área, pedido para ser confirmado, caso não seja confirmado poderá ser informado outra área até que seja confirmado;

3. Inserir Vários Livros (o mesmo que acima, porém ficará em loop até que se deseje encerrar a inserção);

4. Exibir a relação dos livros (isbn, titulo, nome da área, quantidade de cópias, quantidade emprestada);

5. Exibir os dados de um livro por Isbn. (Deverá ser informado o ISBN do livro e exibir todos os campos dados do livro, porém no campo área, deverá exibir além do número da área cadastrado o nome referente a área;

6. Exibir os dados de um livro por Titulo. (Deverá ser informado o Titulo e exibir todos os campos dados do livro, porém no campo área, deverá exibir além do número da área cadastrado o nome referente a área);

7. Buscar livros com título. (Supondo que você não sabe o título completo do livro, esta função servirá para que você coloque o início do título do livro, para retornar todos os títulos que possuem as mesmas iniciais. (exibindo todos os dados tal como o anterior);

8. Editar um Livro (informando o isbn) a edição exibirá os dados atuais do livro e permitirá que o usuário altere algum dos campos (caso o usuário não desejar alterar determinado campo bastaria informar 0 no campo em questão);

9. Realizar empréstimo (através do isbn) – a quantidade emprestada e o empréstimo acumulado são incrementados. O sistema deve garantir que se mantenha pelo menos uma cópia sem ser emprestada;

10. Realizar devolução do livro (através do isbn) – a quantidade emprestada é decrementada;

11. Exibir a relação de livros emprestados (no momento) exibindo no final da relação a Quantidade Total . (exibir o ISBN, título, quantidade de cópias e quantidade emprestada);

12. Exibir a relação de livros emprestados (no momento) de uma determinada área – exibindo no final da relação a Quantidade Total;

13. Exibir os livros emprestado por área (deverá em cada área exibir a relação dos livros atualmente emprestados (exibir o ISBN, título ,quantidade emprestada));

14. Exibir para cada área a quantidade de livros totais emprestados. (utilize o empréstimo acumulado) Ex.:
    História : 20
    Administração: 50
    Literatura: 0

15. Exibir a Quantidade de Livros do Acervo, a Quantidade de Livros atualmente emprestados e a Quantidade Total de Livros emprestados na biblioteca desde que o sistema de controle de acervo foi implantado)
