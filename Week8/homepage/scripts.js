$(document).ready(function() { /* instruçao jquery = inicia script somente quando o doc estiver pronto = carregar todo*/
    //progress bar
    let containerA = document.getElementById("circleA");

    /*objeto de circulo da biblioteca (progress roller)
    com as caracteristicas que ele precisa
    */
    let circleA = new ProgressBar.Circle(containerA, {
    //objetos internos para limitar area
        color: '#edf2f4',
        strokeWidth: 8, //largura do circulo
        duration: 1400,
        from: { color: '#7209b7'}, //inicia com essa cor
        to: { color: '#edf2f4'}, //termina com essa cor

        //Animaçao do circulo = da BIBLIOTECA
        step: function(state, circle) { //state e circle = funçao que eu passei
            circle.path.setAttribute('stroke', state.color);//parte da biblioteca que precisa para criar um circulo animado (js)

            let value = Math.round(circle.value() * 27);

            circle.setText(value);
        }
    });

    let containerB = document.getElementById("circleB");
    let circleB = new ProgressBar.Circle(containerB, {

        color: '#edf2f4',
        strokeWidth: 8,
        duration: 1600,
        from: { color: '#7209b7'},
        to: { color: '#edf2f4'},

        step: function(state, circle) {
            circle.path.setAttribute('stroke', state.color);

            let value = Math.round(circle.value() * 14);

            circle.setText(value);
        }
    });

    let containerC = document.getElementById("circleC");
    let circleC = new ProgressBar.Circle(containerC, {

        color: '#edf2f4',
        strokeWidth: 8,
        duration: 1800,
        from: { color: '#7209b7'},
        to: { color: '#edf2f4'},

        step: function(state, circle) {
            circle.path.setAttribute('stroke', state.color);

            var value = Math.round(circle.value() * 25);

            circle.setText(value);
        }
    });

    let containerD = document.getElementById("circleD");
    let circleD = new ProgressBar.Circle(containerD, {

        color: '#edf2f4',
        strokeWidth: 8,
        duration: 2200,
        from: { color: '#7209b7'},
        to: { color: '#edf2f4'},

        step: function(state, circle) {
            circle.path.setAttribute('stroke', state.color);

             let value = Math.round(circle.value() * 97);

            circle.setText(value);
        }
    });



    let stop = 0;   // stop serve para a animação não carregar mais que uma vez

    $(window).scroll(function (e) { //parametro de evento
        let scroll = $(window).scrollTop();

        if(scroll > 1400 && stop == 0) {//1400px bate certinhp
            //'disparando = pra começar
            circleA.animate(1.0);
            circleB.animate(1.0);
            circleC.animate(1.0);
            circleD.animate(1.0);

            stop = 1;
        }
    });


    //parallax = imagem fixa = ja ta pronto pq eu importei no começo
    setTimeout(function() { //pra carregar as imagens da pagina primeiro (Evita bugs)

        $('#data-area').parallax({imageSrc: 'img/Catedral.jpg'});
        $('#apply-area').parallax({imageSrc: 'img/pattern.jpg'});

    }, 250); //250 milesimos


    

});
//Linha do tempo


