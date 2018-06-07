(function App () {
    const width = window.innerWidth,
        height = window.innerHeight,
        depth = 200;

    const canvas = document.getElementById('canvas');
    const renderer = new THREE.WebGLRenderer({ canvas });
    renderer.setClearColor(0x000000);
    renderer.setSize(width, height);
    renderer.shadowMap.enabled = true;
    renderer.shadowMap.type = THREE.PCFSoftShadowMap;


    const scene = new THREE.Scene();

    const camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 0);
    const controls = new THREE.OrbitControls(camera);
    camera.position.set(0, 0, depth);

    const ambientLight = new THREE.AmbientLight(0x0000ff, 0.2);
    ambientLight.position.set(0, 0, depth);

    const pointLight = new THREE.PointLight(0xff0000, 100);
    pointLight.castShadow = true;
    pointLight.shadow.mapSize.width = 512;
    pointLight.shadow.mapSize.height = 512;
    pointLight.shadow.camera.near = 0.5;
    pointLight.shadow.camera.far = 500;
    pointLight.position.set(0, 0, 0);

    scene.add(ambientLight);
    const PLH = new THREE.PointLightHelper(pointLight);
    scene.add(pointLight);
    scene.add(PLH);

    const material = new THREE.MeshStandardMaterial({
        emissive: 0x708090,
        side: THREE.DoubleSide,
        shading: THREE.FlatShading ,
    });

    const geometry = new THREE.Geometry();

    const points = [
        [0, 0, 0, 0],
        [1, 0, 0, 10],
        [2, 10, 0, 10],
        [3, 10, 0, 0],
        [4, 0, 10, 0],
        [5, 0, 10, 10],
        [6, 10, 10, 10],
        [7, 10, 10, 0],
        [8, 1, 1, 0],
        [9, 1, 1, 10],
        [10, 9, 1, 10],
        [11, 9, 1, 0],
        [12, 1, 9, 0],
        [13, 1, 9, 10],
        [14, 9, 9, 10],
        [15, 9, 9, 0],
        [16, 0, 1, 0],
        [17, 10, 1, 0],
        [18, 0, 9, 0],
        [19, 10, 9, 0],
        [20, 0, 1, 10],
        [21, 10, 1, 10],
        [22, 0, 9, 10],
        [23, 10, 9, 10]
    ];


    points.forEach((point) => {
        geometry.vertices.push(new THREE.Vector3(point[1] * 5 - 25, point[2] * 5 - 25, point[3] * 5 - 25));
    });

    const faces = [
        [0, 1, 2, 3],
        [4, 5, 6, 7],
        [0, 1, 5, 4],
        [3, 2, 6, 7],
        [8, 9, 10, 11],
        [12, 13, 14, 15],
        [8, 9, 13, 12],
        [11, 10, 14, 15],
        [0, 16, 17, 3],
        [18, 4, 7, 19],
        [16, 8, 12, 18],
        [11, 17, 19, 15],
        [1, 20, 21, 2],
        [22, 5, 6, 23],
        [20, 9, 13, 22],
        [10, 21, 23, 14]
    ];

    faces.forEach((face) => {
        geometry.faces.push(new THREE.Face3(face[0], face[1], face[2]));
        geometry.faces.push(new THREE.Face3(face[2], face[3], face[0]));
    });

    const mesh = new THREE.Mesh(geometry, material);
    mesh.castShadow = true;
    mesh.receiveShadow = true;
    scene.add(mesh);

    function loop () {
        controls.update();
        renderer.render(scene, camera);
        requestAnimationFrame(function () {
            loop();
        });
    }

    loop();
})();
